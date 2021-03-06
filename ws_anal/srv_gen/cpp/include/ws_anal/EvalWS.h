/* Auto-generated by genmsg_cpp for file /home/vektor/hiroken-ros-pkg/ws_anal/srv/EvalWS.srv */
#ifndef WS_ANAL_SERVICE_EVALWS_H
#define WS_ANAL_SERVICE_EVALWS_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"




namespace ws_anal
{
template <class ContainerAllocator>
struct EvalWSRequest_ {
  typedef EvalWSRequest_<ContainerAllocator> Type;

  EvalWSRequest_()
  : rbt_id()
  , jspace()
  , path()
  {
  }

  EvalWSRequest_(const ContainerAllocator& _alloc)
  : rbt_id(_alloc)
  , jspace(_alloc)
  , path(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _rbt_id_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  rbt_id;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _jspace_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  jspace;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _path_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  path;


  typedef boost::shared_ptr< ::ws_anal::EvalWSRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ws_anal::EvalWSRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct EvalWSRequest
typedef  ::ws_anal::EvalWSRequest_<std::allocator<void> > EvalWSRequest;

typedef boost::shared_ptr< ::ws_anal::EvalWSRequest> EvalWSRequestPtr;
typedef boost::shared_ptr< ::ws_anal::EvalWSRequest const> EvalWSRequestConstPtr;


template <class ContainerAllocator>
struct EvalWSResponse_ {
  typedef EvalWSResponse_<ContainerAllocator> Type;

  EvalWSResponse_()
  : msg()
  {
  }

  EvalWSResponse_(const ContainerAllocator& _alloc)
  : msg(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _msg_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  msg;


  typedef boost::shared_ptr< ::ws_anal::EvalWSResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ws_anal::EvalWSResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct EvalWSResponse
typedef  ::ws_anal::EvalWSResponse_<std::allocator<void> > EvalWSResponse;

typedef boost::shared_ptr< ::ws_anal::EvalWSResponse> EvalWSResponsePtr;
typedef boost::shared_ptr< ::ws_anal::EvalWSResponse const> EvalWSResponseConstPtr;

struct EvalWS
{

typedef EvalWSRequest Request;
typedef EvalWSResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct EvalWS
} // namespace ws_anal

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::ws_anal::EvalWSRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::ws_anal::EvalWSRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::ws_anal::EvalWSRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "318833947f46332541a8bfbddbb7d0a7";
  }

  static const char* value(const  ::ws_anal::EvalWSRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x318833947f463325ULL;
  static const uint64_t static_value2 = 0x41a8bfbddbb7d0a7ULL;
};

template<class ContainerAllocator>
struct DataType< ::ws_anal::EvalWSRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ws_anal/EvalWSRequest";
  }

  static const char* value(const  ::ws_anal::EvalWSRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::ws_anal::EvalWSRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string rbt_id\n\
string jspace\n\
string path\n\
\n\
";
  }

  static const char* value(const  ::ws_anal::EvalWSRequest_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::ws_anal::EvalWSResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::ws_anal::EvalWSResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::ws_anal::EvalWSResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "7d96ed730776804754140b85e64c862e";
  }

  static const char* value(const  ::ws_anal::EvalWSResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x7d96ed7307768047ULL;
  static const uint64_t static_value2 = 0x54140b85e64c862eULL;
};

template<class ContainerAllocator>
struct DataType< ::ws_anal::EvalWSResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ws_anal/EvalWSResponse";
  }

  static const char* value(const  ::ws_anal::EvalWSResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::ws_anal::EvalWSResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string msg\n\
\n\
\n\
";
  }

  static const char* value(const  ::ws_anal::EvalWSResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::ws_anal::EvalWSRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.rbt_id);
    stream.next(m.jspace);
    stream.next(m.path);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct EvalWSRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::ws_anal::EvalWSResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.msg);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct EvalWSResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<ws_anal::EvalWS> {
  static const char* value() 
  {
    return "a329fccc88163dbeb79aa97ba7444f4c";
  }

  static const char* value(const ws_anal::EvalWS&) { return value(); } 
};

template<>
struct DataType<ws_anal::EvalWS> {
  static const char* value() 
  {
    return "ws_anal/EvalWS";
  }

  static const char* value(const ws_anal::EvalWS&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<ws_anal::EvalWSRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a329fccc88163dbeb79aa97ba7444f4c";
  }

  static const char* value(const ws_anal::EvalWSRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<ws_anal::EvalWSRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ws_anal/EvalWS";
  }

  static const char* value(const ws_anal::EvalWSRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<ws_anal::EvalWSResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a329fccc88163dbeb79aa97ba7444f4c";
  }

  static const char* value(const ws_anal::EvalWSResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<ws_anal::EvalWSResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ws_anal/EvalWS";
  }

  static const char* value(const ws_anal::EvalWSResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // WS_ANAL_SERVICE_EVALWS_H

