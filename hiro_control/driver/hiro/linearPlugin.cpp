// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.

#include "linearPlugin.hpp"
#include <omniORB4/IOP_S.h>
#include <omniORB4/IOP_C.h>
#include <omniORB4/callDescriptor.h>
#include <omniORB4/callHandle.h>
#include <omniORB4/objTracker.h>


OMNI_USING_NAMESPACE(omni)

static const char* _0RL_library_version = omniORB_4_1;



linearPlugin_ptr linearPlugin_Helper::_nil() {
  return ::linearPlugin::_nil();
}

::CORBA::Boolean linearPlugin_Helper::is_nil(::linearPlugin_ptr p) {
  return ::CORBA::is_nil(p);

}

void linearPlugin_Helper::release(::linearPlugin_ptr p) {
  ::CORBA::release(p);
}

void linearPlugin_Helper::marshalObjRef(::linearPlugin_ptr obj, cdrStream& s) {
  ::linearPlugin::_marshalObjRef(obj, s);
}

linearPlugin_ptr linearPlugin_Helper::unmarshalObjRef(cdrStream& s) {
  return ::linearPlugin::_unmarshalObjRef(s);
}

void linearPlugin_Helper::duplicate(::linearPlugin_ptr obj) {
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
}

linearPlugin_ptr
linearPlugin::_duplicate(::linearPlugin_ptr obj)
{
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
  return obj;
}

linearPlugin_ptr
linearPlugin::_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}


linearPlugin_ptr
linearPlugin::_unchecked_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
  return e ? e : _nil();
}

linearPlugin_ptr
linearPlugin::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
  static _objref_linearPlugin _the_nil_obj;
  return &_the_nil_obj;
#else
  static _objref_linearPlugin* _the_nil_ptr = 0;
  if( !_the_nil_ptr ) {
    omni::nilRefLock().lock();
    if( !_the_nil_ptr ) {
      _the_nil_ptr = new _objref_linearPlugin;
      registerNilCorbaObject(_the_nil_ptr);
    }
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
#endif
}

const char* linearPlugin::_PD_repoId = "IDL:linearPlugin:1.0";


typedef OpenHRP::Plugin OpenHRP_Plugin;
typedef OpenHRP::_impl_Plugin OpenHRP__impl_Plugin;
typedef OpenHRP::_objref_Plugin OpenHRP__objref_Plugin;

typedef OpenHRP::CommandReceiver OpenHRP_CommandReceiver;
typedef OpenHRP::_impl_CommandReceiver OpenHRP__impl_CommandReceiver;
typedef OpenHRP::_objref_CommandReceiver OpenHRP__objref_CommandReceiver;

_objref_linearPlugin::~_objref_linearPlugin() {
  
}


_objref_linearPlugin::_objref_linearPlugin(omniIOR* ior, omniIdentity* id) :
   omniObjRef(::linearPlugin::_PD_repoId, ior, id, 1),
   OpenHRP__objref_Plugin(ior, id)
   
{
  _PR_setobj(this);
}

void*
_objref_linearPlugin::_ptrToObjRef(const char* id)
{
  if( id == ::linearPlugin::_PD_repoId )
    return (::linearPlugin_ptr) this;
  if( id == ::OpenHRP::Plugin::_PD_repoId )
    return (::OpenHRP::Plugin_ptr) this;

  if( id == ::OpenHRP::CommandReceiver::_PD_repoId )
    return (::OpenHRP::CommandReceiver_ptr) this;


  if( id == ::CORBA::Object::_PD_repoId )
    return (::CORBA::Object_ptr) this;

  if( omni::strMatch(id, ::linearPlugin::_PD_repoId) )
    return (::linearPlugin_ptr) this;
  if( omni::strMatch(id, ::OpenHRP::Plugin::_PD_repoId) )
    return (::OpenHRP::Plugin_ptr) this;

  if( omni::strMatch(id, ::OpenHRP::CommandReceiver::_PD_repoId) )
    return (::OpenHRP::CommandReceiver_ptr) this;


  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (::CORBA::Object_ptr) this;

  return 0;
}

// Proxy call descriptor class. Mangled signature:
//  _cdouble_i_cunsigned_pshort_i_cstatusPluginTypes_mJointValues_i_cdouble_i_cdouble_o_chiroCommonStatus_mstatSequence
class _0RL_cd_aec14d2c845d9405_00000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_aec14d2c845d9405_00000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  statusPluginTypes::kindType arg_0;
  statusPluginTypes::JointValues_var arg_1_;
  const statusPluginTypes::JointValues* arg_1;
  ::CORBA::Double arg_2;
  ::CORBA::Double arg_3;
  hiroCommonStatus::statSequence_var arg_4;
  ::CORBA::Double result;
};

void _0RL_cd_aec14d2c845d9405_00000000::marshalArguments(cdrStream& _n)
{
  arg_0 >>= _n;
  (const statusPluginTypes::JointValues&) *arg_1 >>= _n;
  arg_2 >>= _n;
  arg_3 >>= _n;

}

void _0RL_cd_aec14d2c845d9405_00000000::unmarshalArguments(cdrStream& _n)
{
  (statusPluginTypes::kindType&)arg_0 <<= _n;
  arg_1_ = new statusPluginTypes::JointValues;
  (statusPluginTypes::JointValues&)arg_1_ <<= _n;
  arg_1 = &arg_1_.in();
  (::CORBA::Double&)arg_2 <<= _n;
  (::CORBA::Double&)arg_3 <<= _n;

}

void _0RL_cd_aec14d2c845d9405_00000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;
  (const hiroCommonStatus::statSequence&) arg_4 >>= _n;

}

void _0RL_cd_aec14d2c845d9405_00000000::unmarshalReturnedValues(cdrStream& _n)
{
  (::CORBA::Double&)result <<= _n;
  arg_4 = new hiroCommonStatus::statSequence;
  (hiroCommonStatus::statSequence&)arg_4 <<= _n;

}

const char* const _0RL_cd_aec14d2c845d9405_00000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_aec14d2c845d9405_10000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_aec14d2c845d9405_00000000* tcd = (_0RL_cd_aec14d2c845d9405_00000000*)cd;
  _impl_linearPlugin* impl = (_impl_linearPlugin*) svnt->_ptrToInterface(linearPlugin::_PD_repoId);
  tcd->result = impl->setPosition(tcd->arg_0, *tcd->arg_1, tcd->arg_2, tcd->arg_3, tcd->arg_4.out());


}

::CORBA::Double _objref_linearPlugin::setPosition(::statusPluginTypes::kindType kind, const ::statusPluginTypes::JointValues& position, ::CORBA::Double minimumTime, ::CORBA::Double percent, ::hiroCommonStatus::statSequence_out status)
{
  _0RL_cd_aec14d2c845d9405_00000000 _call_desc(_0RL_lcfn_aec14d2c845d9405_10000000, "setPosition", 12);
  _call_desc.arg_0 = kind;
  _call_desc.arg_1 = &(::statusPluginTypes::JointValues&) position;
  _call_desc.arg_2 = minimumTime;
  _call_desc.arg_3 = percent;

  _invoke(_call_desc);
  status = _call_desc.arg_4._retn();
  return _call_desc.result;


}
_pof_linearPlugin::~_pof_linearPlugin() {}


omniObjRef*
_pof_linearPlugin::newObjRef(omniIOR* ior, omniIdentity* id)
{
  return new ::_objref_linearPlugin(ior, id);
}


::CORBA::Boolean
_pof_linearPlugin::is_a(const char* id) const
{
  if( omni::ptrStrMatch(id, ::linearPlugin::_PD_repoId) )
    return 1;
  if( omni::ptrStrMatch(id, OpenHRP::Plugin::_PD_repoId) )
    return 1;

  if( omni::ptrStrMatch(id, OpenHRP::CommandReceiver::_PD_repoId) )
    return 1;


  return 0;
}

const _pof_linearPlugin _the_pof_linearPlugin;

_impl_linearPlugin::~_impl_linearPlugin() {}


::CORBA::Boolean
_impl_linearPlugin::_dispatch(omniCallHandle& _handle)
{
  const char* op = _handle.operation_name();

  if( omni::strMatch(op, "setPosition") ) {

    _0RL_cd_aec14d2c845d9405_00000000 _call_desc(_0RL_lcfn_aec14d2c845d9405_10000000, "setPosition", 12, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  
#ifndef _MSC_VER
  if( OpenHRP__impl_Plugin::_dispatch(_handle) ) {
    return 1;
  }
#else
  // Work-around for incorrect MSVC code generation.
  if( ((OpenHRP__impl_Plugin*)this)->
      OpenHRP__impl_Plugin::_dispatch(_handle) ) {
    return 1;
  }
#endif


  return 0;
}

void*
_impl_linearPlugin::_ptrToInterface(const char* id)
{
  if( id == ::linearPlugin::_PD_repoId )
    return (::_impl_linearPlugin*) this;
  if( id == ::OpenHRP::Plugin::_PD_repoId )
    return (::OpenHRP::_impl_Plugin*) this;

  if( id == ::OpenHRP::CommandReceiver::_PD_repoId )
    return (::OpenHRP::_impl_CommandReceiver*) this;


  if( id == ::CORBA::Object::_PD_repoId )
    return (void*) 1;

  if( omni::strMatch(id, ::linearPlugin::_PD_repoId) )
    return (::_impl_linearPlugin*) this;
  if( omni::strMatch(id, ::OpenHRP::Plugin::_PD_repoId) )
    return (::OpenHRP::_impl_Plugin*) this;

  if( omni::strMatch(id, ::OpenHRP::CommandReceiver::_PD_repoId) )
    return (::OpenHRP::_impl_CommandReceiver*) this;


  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (void*) 1;
  return 0;
}

const char*
_impl_linearPlugin::_mostDerivedRepoId()
{
  return ::linearPlugin::_PD_repoId;
}

POA_linearPlugin::~POA_linearPlugin() {}

