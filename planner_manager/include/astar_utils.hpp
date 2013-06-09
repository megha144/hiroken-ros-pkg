#ifndef ASTAR_UTILS_HPP_INCLUDED
#define ASTAR_UTILS_HPP_INCLUDED

#include "astar_utils.hpp"

#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/astar_search.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/random.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/property_iter_range.hpp>

#include <lwpr.hh>

#include "geo_planner_manager.hpp"
#include "data.hpp"
#include "ml_util.hpp"

using namespace std;
using namespace boost;

struct FoundGoalSignal {}; // exception for termination

template <typename GPMGraph,typename LearningMachine>
class AstarVisitor: public boost::default_astar_visitor
{
public:
AstarVisitor(typename GPMGraph::vertex_descriptor goal, GeometricPlannerManager* gpm,LearningMachine* learner,std::vector< std::vector<double> >* ml_data,size_t ml_mode,std::string ml_hot_path,double* total_gp_time)
: goal_(goal), gpm_(gpm), learner_(learner), ml_data_(ml_data), ml_mode_(ml_mode), ml_hot_path_(ml_hot_path), total_gp_time_(total_gp_time)
{ }

template <typename Graph>
void 
examine_vertex(typename Graph::vertex_descriptor v, Graph& g) 
{
  cerr << "Examine v= " << get(vertex_name,g,v) << endl;
  gpm_->mark_vertex(v);// Set its color to black=examined
  
  if(v == goal_)
  {
    // Store the updated model for the next CTAMP attempt
    if(ml_mode_ == ml_util::LWPR_ONLINE)
    {
      if(  !learner_->writeBinary( std::string(ml_hot_path_+"/lwpr.bin").c_str() )  )
        std::cerr << "learner_->writeBinary()= NOT OK" << std::endl;
    }
      
    throw FoundGoalSignal();
  }

  // Do geometric planning (grasp and motion planning) for each out-edge of this vertex v
  std::vector<typename Graph::edge_descriptor> ungraspable_edges;// invalid because no grasp/ungrasp pose as the goal pose for the motion planning
  
  typename graph_traits<Graph>::out_edge_iterator oei, oei_end;
  for(tie(oei,oei_end) = out_edges(v, g); oei!=oei_end; ++oei)
  {
    double gp_time = 0.;
    bool success = false;
    
    success = gpm_->plan(*oei,&gp_time);
    
    *total_gp_time_ += gp_time;
    
    if(!success)
      ungraspable_edges.push_back(*oei);
  }
  
  for(typename std::vector<typename Graph::edge_descriptor>::iterator i=ungraspable_edges.begin(); i!=ungraspable_edges.end(); ++i)
    gpm_->remove_ungraspable_edge(*i);
  
  // Update jstates of adjacent vertex av of this vertex v to the cheapest existing-just-planned edge
  gpm_->set_av_jstates(v); 

  // Obtain samples from paths from (root,root+1, ..., v) to adjacent of v where the edge costs are already defined
  Data samples;
  gpm_->get_samples_online(v,&samples);
//    cerr << "online training: samples.size()= " << samples.size() << endl;

  // Utilize samples
  if((ml_mode_ == ml_util::SVR_OFFLINE)or(ml_mode_ == ml_util::NO_ML_BUT_COLLECTING_SAMPLES))// Store samples for offline (interleaved) training and for offline tuning
  {
    // Write samples + the delta to a libsvmdata format: APPENDING
    std::string libsvmdata_path = std::string(ml_hot_path_+"/tr_data.libsvmdata");;
    std::string delta_libsvmdata_path = std::string(ml_hot_path_+"/delta_tr_data.libsvmdata");
    
    data_util::write_libsvm_data(samples,libsvmdata_path,std::ios::app);
    data_util::write_libsvm_data(samples,delta_libsvmdata_path,std::ios::app);
    
    // Write samples + the delta to a CSV format: APPENDING
    std::string csv_path = std::string(ml_hot_path_+"/tr_data.csv");
    std::string delta_csv_path = std::string(ml_hot_path_+"/delta_tr_data.csv");
    
    data_util::write_csv_data(samples,csv_path,std::ios::app);
    data_util::write_csv_data(samples,delta_csv_path,std::ios::app);
  }
  else if(ml_mode_==ml_util::LWPR_ONLINE)// Train online during search (the online LWPR)
  {
    for(Data::const_iterator i=samples.begin(); i!=samples.end(); ++i)
    {
      std::vector<double> x;
      x = i->first;// input
      
      std::vector<double> y(1);
      y.at(0) = i->second;// observed output

      std::vector<double> y_fit_test;// for prediction before the model is updated with this samples
      y_fit_test = learner_->predict(x);

      std::vector<double> y_fit;// for prediction on training data
      y_fit = learner_->update( x,y );// likely that this prediction after the model is updated, it differs from the prediction before updating 
//      cerr << "y_fit= " << y_fit.at(0) << endl;
      
      if( y_fit.empty() )
      {
        std::cerr << "update(x,y)= NOT OK" << std::endl;
        continue;// with the next samples
      }
      
      // Keep ml-related data 
      std::vector<double> ml_datum;
      ml_datum.push_back(y_fit_test.at(0));// 0 
      ml_datum.push_back(y_fit.at(0));// 1
      ml_datum.push_back(y.at(0));// 2
      ml_datum.push_back(learner_->nData());// 3
      
      ml_data_->push_back(ml_datum);
    }
  }
  else// ml_mode_==ml_util::NO_ML
  {
    // do nothing
  }
}
  
template <typename Graph>
void 
initialize_vertex(typename Graph::vertex_descriptor v, Graph& g) 
{
  gpm_->init_vertex(v);
}
  
private:
typename GPMGraph::vertex_descriptor goal_;
GeometricPlannerManager* gpm_;
LearningMachine* learner_;  
std::vector< std::vector<double> >* ml_data_;
size_t ml_mode_;
std::string ml_hot_path_;
double* total_gp_time_;

};

template <typename GPMGraph, typename CostType, typename LearningMachine>
class AstarHeuristics: public astar_heuristic<GPMGraph, CostType>
{
public:
typedef typename graph_traits<GPMGraph>::vertex_descriptor Vertex;

AstarHeuristics(typename GPMGraph::vertex_descriptor goal, GeometricPlannerManager* gpm,LearningMachine* learner,size_t ml_mode,ml_util::PrepData prep_data)
: goal_(goal), gpm_(gpm), learner_(learner), ml_mode_(ml_mode), prep_data_(prep_data)
{ }

CostType 
operator()(Vertex v)
{
  cerr << "Compute h(" << v << "): BEGIN" << endl;
  double h;
  
  if(v == goal_)
  {
    cerr << "(v==goal_) -> h = 0." << endl;
    h = 0.;
  }
  else if((ml_mode_ == ml_util::NO_ML)or(ml_mode_ == ml_util::NO_ML_BUT_COLLECTING_SAMPLES))
  {
    cerr << "(ml_mode_==NO_ML or NO_ML_BUT_COLLECTING_SAMPLES) -> h = 0." << endl;
    h = 0.;
  }
  else if( (ml_mode_ == ml_util::SVR_OFFLINE) or (ml_mode_ == ml_util::LWPR_ONLINE) )
  {
    // Extract feature x
    Input x;
    if ( !gpm_->get_fval(v,&x) )
    {
      // This happens when there is no goal-reached path from v, which means that definitely this vertex v does not belong to solution path.
      // Therefore, we impose a very high value on h, which causes that this path will never expanded!
      cerr << "!gpm_->get_fval(v,&x) -> h = (a very high value)" << endl;
      h = std::numeric_limits<double>::max();
    }
    else
    {
      // Preprocess data if necessary
      bool has_to_prep_data = false;
      bool has_to_postp_data = false;
      
      if(ml_mode_ == ml_util::SVR_OFFLINE)
      {
        has_to_prep_data = true;
        has_to_postp_data = true;
      }
        
      if(has_to_prep_data)
      {
        // All below should mimic the proprocess_data() routine implemented in matlab
        double* x_ptr = &x[0];
        Eigen::Map<Eigen::VectorXd> tmp_x(x_ptr,x.size());
        
        // Centering; PCA needs centered_x
        Eigen::VectorXd centered_x;
        centered_x = tmp_x - prep_data_.mu_X;
        
        // Project to new space
        Eigen::VectorXd new_x;
        new_x = centered_x * prep_data_.T;
        
        // Reduce dim
        Eigen::VectorXd lodim_x;
        lodim_x = new_x.head(prep_data_.lo_dim);
        
        // Convert back to std::vector
        x.clear();
        x.resize(lodim_x.size());
        for(size_t i=0; i<lodim_x.size(); ++i)
          x.at(i) = lodim_x(i);
      }
        
      // Predict yp with the learning machine
      std::vector<double> yp;
      yp = learner_->predict(x);

      // Assign
      if( !yp.empty() )
      {
        if(has_to_postp_data)
        {
          yp.at(0) += prep_data_.mu_y(0);
        }
        
        // Scaling, its dual (scale-down) is in get_out() at file:data_collector.hpp
        // TODO better if done together in postp_data()
        const double scale_up = 10.;
        h = yp.at(0) * scale_up;
      }
      else
      {
        cerr << "yp.empty() -> learner_->predict(x) FAILED -> h = 0." << endl;
        h = 0.;
      }
    }
  }
  
  // Put in the main tmm!
  if(h < 0.) h = 0.;
  cerr << "h(" << v << ")= " << h << endl;
  gpm_->put_heu(v,h);
  
  cerr << "Compute h(" << v << "): END" << endl;
  return h;
}

private:
Vertex goal_;
GeometricPlannerManager* gpm_;
LearningMachine* learner_;
size_t ml_mode_;
ml_util::PrepData prep_data_;
};

#endif // #ifndef ASTAR_UTILS_HPP_INCLUDED
