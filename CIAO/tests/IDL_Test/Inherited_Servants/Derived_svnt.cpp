// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.5
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1147

#include "Derived_svnt.h"
#include "Derived_svnt_T.h"
#include "ciao/Valuetype_Factories/Cookies.h"
#include "tao/SystemException.h"
#include "tao/Valuetype/ValueFactory.h"
#include "tao/ORB_Core.h"
#include "ace/SString.h"

// namespace CIAO_FACET_Inherited
// {
//   derived_interface_Servant::derived_interface_Servant (
//       ::Inherited::CCM_derived_interface_ptr executor,
//       ::Components::CCMContext_ptr ctx)
//     : executor_ ( ::Inherited::CCM_derived_interface::_duplicate (executor)),
//       ctx_ ( ::Components::CCMContext::_duplicate (ctx))
//   {
//   }
//
//   derived_interface_Servant::~derived_interface_Servant (void)
//   {
//   }
//
//   // All facet operations and attributes.
//
//   void
//   derived_interface_Servant::do_derived (
//     void)
//   {
//     ::Inherited::CCM_derived_interface_var executor =
//       ::Inherited::CCM_derived_interface::_duplicate (this->executor_.in ());
//
//     if ( ::CORBA::is_nil (executor.in ()))
//       {
//         throw ::CORBA::INV_OBJREF ();
//       }
//
//     executor->do_derived ();
//   }
//
//   ::CORBA::Object_ptr
//   derived_interface_Servant::_get_component (void)
//   {
//     ::Components::SessionContext_var sc =
//       ::Components::SessionContext::_narrow (this->ctx_.in ());
//
//     if (! ::CORBA::is_nil (sc.in ()))
//       {
//         return sc->get_CCM_object ();
//       }
//
//     throw ::CORBA::INTERNAL ();
//   }
// }

namespace CIAO_Inherited_Derived_comp_Impl
{
  Derived_comp_Context::Derived_comp_Context (
      ::Components::CCMHome_ptr h,
      ::CIAO::Session_Container_ptr c,
      PortableServer::Servant sv,
    const char *id)
  : ::CIAO::Context_Impl_Base_T < ::CIAO::Session_Container> (h, c, id),
    ::CIAO::Session_Context_Impl<
      ::Inherited::CCM_Derived_comp_Context,
      ::Inherited::Derived_comp> (h, c, sv, id)
  {
  }

  Derived_comp_Context::~Derived_comp_Context (void)
  {
  }

  ::Inherited::derived_interface_ptr
  Derived_comp_Context::get_connection_uses_derived (void)
  {
    return ::Inherited::derived_interface::_duplicate (
      this->ciao_uses_uses_derived_.in ());
  }

  void
  Derived_comp_Context::connect_uses_derived (
    ::Inherited::derived_interface_ptr c)
  {
    if ( ::CORBA::is_nil (c))
      {
        throw ::Components::InvalidConnection ();
      }

    if (! ::CORBA::is_nil (this->ciao_uses_uses_derived_.in ()))
      {
        throw ::Components::AlreadyConnected ();
      }

    this->ciao_uses_uses_derived_ =
      ::Inherited::derived_interface::_duplicate (c);
  }

  ::Inherited::derived_interface_ptr
  Derived_comp_Context::disconnect_uses_derived (void)
  {
    ::Inherited::derived_interface_var ciao_uses_uses_derived =
      this->ciao_uses_uses_derived_._retn ();

    if ( ::CORBA::is_nil (ciao_uses_uses_derived.in ()))
      {
        throw ::Components::NoConnection ();
      }

    return ciao_uses_uses_derived._retn ();
  }

  Derived_comp_Servant::Derived_comp_Servant (
        ::Inherited::CCM_Derived_comp_ptr exe,
        ::Components::CCMHome_ptr h,
        const char * ins_name,
        ::CIAO::Home_Servant_Impl_Base * hs,
        ::CIAO::Session_Container_ptr c)
    : ::CIAO::Connector_Servant_Impl_Base (h, hs, c),
      ::CIAO::Session_Servant_Impl<
        ::POA_Inherited::Derived_comp,
        ::Inherited::CCM_Derived_comp,
        Derived_comp_Context> (exe, h, ins_name, hs, c)
  {

    this->setup_prov_derived_i ();
  }

  Derived_comp_Servant::~Derived_comp_Servant (void)
  {
  }

  /// Supported operations and attributes.

  /// All ports and component attributes.

  /// CIAO-specific.
  ::CORBA::Object_ptr
  Derived_comp_Servant::get_facet_executor (
    const char * name)
  {
    if (name == 0)
      {
        throw ::CORBA::BAD_PARAM ();
      }

    ::Inherited::CCM_Derived_comp_var executor =
      ::Inherited::CCM_Derived_comp::_duplicate (this->executor_.in ());

    if ( ::CORBA::is_nil (executor.in ()))
      {
        throw ::CORBA::INV_OBJREF ();
      }

    if (ACE_OS::strcmp (name, "prov_derived") == 0)
      {
        return executor->get_prov_derived ();
      }

    throw ::Components::InvalidName ();
  }

  ::Components::Cookie *
  Derived_comp_Servant::connect (
    const char * name,
    ::CORBA::Object_ptr connection)
  {
    if (name == 0)
      {
        throw ::CORBA::BAD_PARAM ();
      }

    if (ACE_OS::strcmp (name, "uses_derived") == 0)
      {
        ::Inherited::derived_interface_var _ciao_conn =
          ::Inherited::derived_interface::_narrow (connection);

        /// Simplex connect.
        this->context_->connect_uses_derived (_ciao_conn.in ());
        return 0;
      }

    throw ::Components::InvalidName ();
  }

  ::CORBA::Object_ptr
  Derived_comp_Servant::disconnect (
    const char * name,
    ::Components::Cookie * /* ck */)
  {
    if (name == 0)
      {
        throw ::CORBA::BAD_PARAM ();
      }

    if (ACE_OS::strcmp (name, "uses_derived") == 0)
      {
        /// Simplex disconnect.
        return this->context_->disconnect_uses_derived ();
      }

    throw ::Components::InvalidName ();
  }

  ::Components::ReceptacleDescriptions *
  Derived_comp_Servant::get_all_receptacles (void)
  {
    ::Components::ReceptacleDescriptions * retval = 0;
    ACE_NEW_THROW_EX (retval,
                      ::Components::ReceptacleDescriptions,
                      ::CORBA::NO_MEMORY ());

    ::Components::ReceptacleDescriptions_var safe_retval = retval;
    safe_retval->length (1UL);

    Inherited::derived_interface_var ciao_uses_derived =
      this->context_->get_connection_uses_derived ();
    ::CIAO::Servant::describe_simplex_receptacle<
      ::Inherited::derived_interface> (
        "uses_derived",
        "IDL:Inherited/derived_interface:1.0",
        ciao_uses_derived.in (),
        safe_retval,
        0UL);

    return safe_retval._retn ();
  }

  ::Inherited::derived_interface_ptr
  Derived_comp_Servant::provide_prov_derived (void)
  {
    return
      ::Inherited::derived_interface::_duplicate (this->provide_prov_derived_.in ());
  }

  void
  Derived_comp_Servant::setup_prov_derived_i (void)
  {
    ACE_CString obj_id (this->ins_name_);
    obj_id += "_prov_derived";

    ::CIAO::Container_var cnt_safe =
      ::CIAO::Container::_duplicate (this->container_.in ());

    if (::CORBA::is_nil (cnt_safe.in ()))
      {
        throw ::CORBA::INV_OBJREF ();
      }

    PortableServer::POA_var POA = cnt_safe->the_port_POA ();
    ::CORBA::Object_var tmp =
      this->get_facet_executor ("prov_derived");

    typedef ::CIAO_FACET_Inherited::derived_interface_Servant_T<POA_Inherited::derived_interface,
                                                              ::Inherited::CCM_derived_interface>
            derived_interface_Servant_type;

    //TODO: pass tmp to the Servant_type and narrow this in Servant_Interface_Base_T
    ::Inherited::CCM_derived_interface_var tmp_var =
      ::Inherited::CCM_derived_interface::_narrow (tmp.in());

    derived_interface_Servant_type * prov_derived_servant_impl = 0;
    ACE_NEW_THROW_EX (
      prov_derived_servant_impl,
      derived_interface_Servant_type (
        tmp_var.in(),
        this->context_),
      CORBA::NO_MEMORY ());

    PortableServer::ServantBase_var safe_base_servant (prov_derived_servant_impl);

    PortableServer::ObjectId_var prov_derived_servant_oid =
      PortableServer::string_to_ObjectId (obj_id.c_str());

    POA->activate_object_with_id(prov_derived_servant_oid.in(),prov_derived_servant_impl);
    ::CORBA::Object_var prov_derived_servant_impl_obj =
      cnt_safe->generate_reference (
        obj_id.c_str (),
        "IDL:Inherited/derived_interface:1.0",
        ::CIAO::Container_Types::FACET_CONSUMER_t);

    this->add_facet ("prov_derived", prov_derived_servant_impl_obj.in ());
  }

  void
  Derived_comp_Servant::connect_uses_derived (
    ::Inherited::derived_interface_ptr c)
  {
    this->context_->connect_uses_derived (c);
  }

  ::Inherited::derived_interface_ptr
  Derived_comp_Servant::disconnect_uses_derived (void)
  {
    return this->context_->disconnect_uses_derived ();
  }

  ::Inherited::derived_interface_ptr
  Derived_comp_Servant::get_connection_uses_derived (void)
  {
    return this->context_->get_connection_uses_derived ();
  }

  extern "C" IS_DERIVED_SVNT_Export ::PortableServer::Servant
  create_Inherited_Derived_comp_Servant (
    ::Components::EnterpriseComponent_ptr p,
    ::CIAO::Session_Container_ptr c,
    const char * ins_name)
  {
    ::Inherited::CCM_Derived_comp_var x =
      ::Inherited::CCM_Derived_comp::_narrow (p);

    ::PortableServer::Servant retval = 0;
    if (! ::CORBA::is_nil (x.in ()))
      {
        ACE_NEW_NORETURN (retval,
                          Derived_comp_Servant (
                            x.in (),
                            ::Components::CCMHome::_nil (),
                            ins_name,
                            0,
                            c));
      }

    return retval;
  }
}

// namespace CIAO_FACET_Inherited
// {
//   derived_2_interface_Servant::derived_2_interface_Servant (
//       ::Inherited::CCM_derived_2_interface_ptr executor,
//       ::Components::CCMContext_ptr ctx)
//     : executor_ ( ::Inherited::CCM_derived_2_interface::_duplicate (executor)),
//       ctx_ ( ::Components::CCMContext::_duplicate (ctx))
//   {
//   }
//
//   derived_2_interface_Servant::~derived_2_interface_Servant (void)
//   {
//   }
//
//   // All facet operations and attributes.
//
//   void
//   derived_2_interface_Servant::do_derived (
//     void)
//   {
//     ::Inherited::CCM_derived_2_interface_var executor =
//       ::Inherited::CCM_derived_2_interface::_duplicate (this->executor_.in ());
//
//     if ( ::CORBA::is_nil (executor.in ()))
//       {
//         throw ::CORBA::INV_OBJREF ();
//       }
//
//     executor->do_derived ();
//   }
//
//   void
//   derived_2_interface_Servant::do_derived_2 (
//     void)
//   {
//     ::Inherited::CCM_derived_2_interface_var executor =
//       ::Inherited::CCM_derived_2_interface::_duplicate (this->executor_.in ());
//
//     if ( ::CORBA::is_nil (executor.in ()))
//       {
//         throw ::CORBA::INV_OBJREF ();
//       }
//
//     executor->do_derived_2 ();
//   }
//
//   ::CORBA::Object_ptr
//   derived_2_interface_Servant::_get_component (void)
//   {
//     ::Components::SessionContext_var sc =
//       ::Components::SessionContext::_narrow (this->ctx_.in ());
//
//     if (! ::CORBA::is_nil (sc.in ()))
//       {
//         return sc->get_CCM_object ();
//       }
//
//     throw ::CORBA::INTERNAL ();
//   }
// }

namespace CIAO_Inherited_Derived_2_comp_Impl
{
  Derived_2_comp_Context::Derived_2_comp_Context (
      ::Components::CCMHome_ptr h,
      ::CIAO::Session_Container_ptr c,
      PortableServer::Servant sv,
    const char *id)
  : ::CIAO::Context_Impl_Base_T < ::CIAO::Session_Container> (h, c, id),
    ::CIAO::Session_Context_Impl<
      ::Inherited::CCM_Derived_2_comp_Context,
      ::Inherited::Derived_2_comp> (h, c, sv, id)
  {
  }

  Derived_2_comp_Context::~Derived_2_comp_Context (void)
  {
  }

  ::Inherited::derived_2_interface_ptr
  Derived_2_comp_Context::get_connection_uses_derived_2 (void)
  {
    return ::Inherited::derived_2_interface::_duplicate (
      this->ciao_uses_uses_derived_2_.in ());
  }

  void
  Derived_2_comp_Context::connect_uses_derived_2 (
    ::Inherited::derived_2_interface_ptr c)
  {
    if ( ::CORBA::is_nil (c))
      {
        throw ::Components::InvalidConnection ();
      }

    if (! ::CORBA::is_nil (this->ciao_uses_uses_derived_2_.in ()))
      {
        throw ::Components::AlreadyConnected ();
      }

    this->ciao_uses_uses_derived_2_ =
      ::Inherited::derived_2_interface::_duplicate (c);
  }

  ::Inherited::derived_2_interface_ptr
  Derived_2_comp_Context::disconnect_uses_derived_2 (void)
  {
    ::Inherited::derived_2_interface_var ciao_uses_uses_derived_2 =
      this->ciao_uses_uses_derived_2_._retn ();

    if ( ::CORBA::is_nil (ciao_uses_uses_derived_2.in ()))
      {
        throw ::Components::NoConnection ();
      }

    return ciao_uses_uses_derived_2._retn ();
  }

  ::Inherited::derived_interface_ptr
  Derived_2_comp_Context::get_connection_uses_derived (void)
  {
    return ::Inherited::derived_interface::_duplicate (
      this->ciao_uses_uses_derived_.in ());
  }

  void
  Derived_2_comp_Context::connect_uses_derived (
    ::Inherited::derived_interface_ptr c)
  {
    if ( ::CORBA::is_nil (c))
      {
        throw ::Components::InvalidConnection ();
      }

    if (! ::CORBA::is_nil (this->ciao_uses_uses_derived_.in ()))
      {
        throw ::Components::AlreadyConnected ();
      }

    this->ciao_uses_uses_derived_ =
      ::Inherited::derived_interface::_duplicate (c);
  }

  ::Inherited::derived_interface_ptr
  Derived_2_comp_Context::disconnect_uses_derived (void)
  {
    ::Inherited::derived_interface_var ciao_uses_uses_derived =
      this->ciao_uses_uses_derived_._retn ();

    if ( ::CORBA::is_nil (ciao_uses_uses_derived.in ()))
      {
        throw ::Components::NoConnection ();
      }

    return ciao_uses_uses_derived._retn ();
  }

  Derived_2_comp_Servant::Derived_2_comp_Servant (
        ::Inherited::CCM_Derived_2_comp_ptr exe,
        ::Components::CCMHome_ptr h,
        const char * ins_name,
        ::CIAO::Home_Servant_Impl_Base * hs,
        ::CIAO::Session_Container_ptr c)
    : ::CIAO::Connector_Servant_Impl_Base (h, hs, c),
      ::CIAO::Session_Servant_Impl<
        ::POA_Inherited::Derived_2_comp,
        ::Inherited::CCM_Derived_2_comp,
        Derived_2_comp_Context> (exe, h, ins_name, hs, c)
  {

    this->setup_prov_derived_2_i ();
    this->setup_prov_derived_i ();
  }

  Derived_2_comp_Servant::~Derived_2_comp_Servant (void)
  {
  }

  /// Supported operations and attributes.

  /// All ports and component attributes.

  /// CIAO-specific.
  ::CORBA::Object_ptr
  Derived_2_comp_Servant::get_facet_executor (
    const char * name)
  {
    if (name == 0)
      {
        throw ::CORBA::BAD_PARAM ();
      }

    ::Inherited::CCM_Derived_2_comp_var executor =
      ::Inherited::CCM_Derived_2_comp::_duplicate (this->executor_.in ());

    if ( ::CORBA::is_nil (executor.in ()))
      {
        throw ::CORBA::INV_OBJREF ();
      }

    if (ACE_OS::strcmp (name, "prov_derived_2") == 0)
      {
        return executor->get_prov_derived_2 ();
      }

    if (ACE_OS::strcmp (name, "prov_derived") == 0)
      {
        return executor->get_prov_derived ();
      }

    throw ::Components::InvalidName ();
  }

  ::Components::Cookie *
  Derived_2_comp_Servant::connect (
    const char * name,
    ::CORBA::Object_ptr connection)
  {
    if (name == 0)
      {
        throw ::CORBA::BAD_PARAM ();
      }

    if (ACE_OS::strcmp (name, "uses_derived_2") == 0)
      {
        ::Inherited::derived_2_interface_var _ciao_conn =
          ::Inherited::derived_2_interface::_narrow (connection);

        /// Simplex connect.
        this->context_->connect_uses_derived_2 (_ciao_conn.in ());
        return 0;
      }

    if (ACE_OS::strcmp (name, "uses_derived") == 0)
      {
        ::Inherited::derived_interface_var _ciao_conn =
          ::Inherited::derived_interface::_narrow (connection);

        /// Simplex connect.
        this->context_->connect_uses_derived (_ciao_conn.in ());
        return 0;
      }

    throw ::Components::InvalidName ();
  }

  ::CORBA::Object_ptr
  Derived_2_comp_Servant::disconnect (
    const char * name,
    ::Components::Cookie * /* ck */)
  {
    if (name == 0)
      {
        throw ::CORBA::BAD_PARAM ();
      }

    if (ACE_OS::strcmp (name, "uses_derived_2") == 0)
      {
        /// Simplex disconnect.
        return this->context_->disconnect_uses_derived_2 ();
      }

    if (ACE_OS::strcmp (name, "uses_derived") == 0)
      {
        /// Simplex disconnect.
        return this->context_->disconnect_uses_derived ();
      }

    throw ::Components::InvalidName ();
  }

  ::Components::ReceptacleDescriptions *
  Derived_2_comp_Servant::get_all_receptacles (void)
  {
    ::Components::ReceptacleDescriptions * retval = 0;
    ACE_NEW_THROW_EX (retval,
                      ::Components::ReceptacleDescriptions,
                      ::CORBA::NO_MEMORY ());

    ::Components::ReceptacleDescriptions_var safe_retval = retval;
    safe_retval->length (2UL);

    Inherited::derived_2_interface_var ciao_uses_derived_2 =
      this->context_->get_connection_uses_derived_2 ();
    ::CIAO::Servant::describe_simplex_receptacle<
      ::Inherited::derived_2_interface> (
        "uses_derived_2",
        "IDL:Inherited/derived_2_interface:1.0",
        ciao_uses_derived_2.in (),
        safe_retval,
        0UL);

    Inherited::derived_interface_var ciao_uses_derived =
      this->context_->get_connection_uses_derived ();
    ::CIAO::Servant::describe_simplex_receptacle<
      ::Inherited::derived_interface> (
        "uses_derived",
        "IDL:Inherited/derived_interface:1.0",
        ciao_uses_derived.in (),
        safe_retval,
        1UL);

    return safe_retval._retn ();
  }

  ::Inherited::derived_2_interface_ptr
  Derived_2_comp_Servant::provide_prov_derived_2 (void)
  {
    return
      ::Inherited::derived_2_interface::_duplicate (this->provide_prov_derived_2_.in ());
  }

  void
  Derived_2_comp_Servant::setup_prov_derived_2_i (void)
  {
    ACE_CString obj_id (this->ins_name_);
    obj_id += "_prov_derived_2";

    ::CIAO::Container_var cnt_safe =
      ::CIAO::Container::_duplicate (this->container_.in ());

    if (::CORBA::is_nil (cnt_safe.in ()))
      {
        throw ::CORBA::INV_OBJREF ();
      }

    PortableServer::POA_var POA = cnt_safe->the_port_POA ();
    ::CORBA::Object_var tmp = this->get_facet_executor ("prov_derived_2");
    ::CORBA::Object_var tmp_base = this->get_facet_executor ("prov_derived");

    typedef ::CIAO_FACET_Inherited::derived_interface_2_Servant_T<POA_Inherited::derived_2_interface,
                                                                ::Inherited::CCM_derived_2_interface,
                                                                POA_Inherited::derived_interface,
                                                                ::Inherited::CCM_derived_interface>
            derived_2_interface_Servant_type;

    //TODO: pass tmp to the Servant_type and narrow this in Servant_Interface_Base_T
    ::Inherited::CCM_derived_2_interface_var tmp_var =
      ::Inherited::CCM_derived_2_interface::_narrow (tmp.in());
    ::Inherited::CCM_derived_interface_var tmp_var_base =
      ::Inherited::CCM_derived_interface::_narrow (tmp_base.in());

    derived_2_interface_Servant_type * prov_derived_2_servant_impl = 0;
    ACE_NEW_THROW_EX (
      prov_derived_2_servant_impl,
      derived_2_interface_Servant_type (
        tmp_var.in(),
        tmp_var_base.in (),
        this->context_),
      CORBA::NO_MEMORY ());

    PortableServer::ServantBase_var safe_base_servant (prov_derived_2_servant_impl);

    PortableServer::ObjectId_var prov_derived_2_servant_oid =
      PortableServer::string_to_ObjectId (obj_id.c_str());

    POA->activate_object_with_id(prov_derived_2_servant_oid.in(),prov_derived_2_servant_impl);
    ::CORBA::Object_var prov_derived_2_servant_impl_obj =
      cnt_safe->generate_reference (
        obj_id.c_str (),
        "IDL:Inherited/derived_2_interface:1.0",
        ::CIAO::Container_Types::FACET_CONSUMER_t);

    this->add_facet ("prov_derived_2", prov_derived_2_servant_impl_obj.in ());
  }

  void
  Derived_2_comp_Servant::connect_uses_derived_2 (
    ::Inherited::derived_2_interface_ptr c)
  {
    this->context_->connect_uses_derived_2 (c);
  }

  ::Inherited::derived_2_interface_ptr
  Derived_2_comp_Servant::disconnect_uses_derived_2 (void)
  {
    return this->context_->disconnect_uses_derived_2 ();
  }

  ::Inherited::derived_2_interface_ptr
  Derived_2_comp_Servant::get_connection_uses_derived_2 (void)
  {
    return this->context_->get_connection_uses_derived_2 ();
  }

  ::Inherited::derived_interface_ptr
  Derived_2_comp_Servant::provide_prov_derived (void)
  {
    return
      ::Inherited::derived_interface::_duplicate (this->provide_prov_derived_.in ());
  }

  void
  Derived_2_comp_Servant::setup_prov_derived_i (void)
  {
    ACE_CString obj_id (this->ins_name_);
    obj_id += "_prov_derived";

    ::CIAO::Container_var cnt_safe =
      ::CIAO::Container::_duplicate (this->container_.in ());

    if (::CORBA::is_nil (cnt_safe.in ()))
      {
        throw ::CORBA::INV_OBJREF ();
      }

    PortableServer::POA_var POA = cnt_safe->the_port_POA ();
    ::CORBA::Object_var tmp =
      this->get_facet_executor ("prov_derived");

    typedef ::CIAO_FACET_Inherited::derived_interface_Servant_T<POA_Inherited::derived_interface,
                                                              ::Inherited::CCM_derived_interface>
            derived_interface_Servant_type;

    //TODO: pass tmp to the Servant_type and narrow this in Servant_Interface_Base_T
    ::Inherited::CCM_derived_interface_var tmp_var =
      ::Inherited::CCM_derived_interface::_narrow (tmp.in());

    derived_interface_Servant_type * prov_derived_servant_impl = 0;
    ACE_NEW_THROW_EX (
      prov_derived_servant_impl,
      derived_interface_Servant_type (
        tmp_var.in(),
        this->context_),
      CORBA::NO_MEMORY ());

    PortableServer::ServantBase_var safe_base_servant (prov_derived_servant_impl);

    PortableServer::ObjectId_var prov_derived_servant_oid =
      PortableServer::string_to_ObjectId (obj_id.c_str());

    POA->activate_object_with_id(prov_derived_servant_oid.in(),prov_derived_servant_impl);
    ::CORBA::Object_var prov_derived_servant_impl_obj =
      cnt_safe->generate_reference (
        obj_id.c_str (),
        "IDL:Inherited/derived_interface:1.0",
        ::CIAO::Container_Types::FACET_CONSUMER_t);

    this->add_facet ("prov_derived", prov_derived_servant_impl_obj.in ());
  }

  void
  Derived_2_comp_Servant::connect_uses_derived (
    ::Inherited::derived_interface_ptr c)
  {
    this->context_->connect_uses_derived (c);
  }

  ::Inherited::derived_interface_ptr
  Derived_2_comp_Servant::disconnect_uses_derived (void)
  {
    return this->context_->disconnect_uses_derived ();
  }

  ::Inherited::derived_interface_ptr
  Derived_2_comp_Servant::get_connection_uses_derived (void)
  {
    return this->context_->get_connection_uses_derived ();
  }

  extern "C" IS_DERIVED_SVNT_Export ::PortableServer::Servant
  create_Inherited_Derived_2_comp_Servant (
    ::Components::EnterpriseComponent_ptr p,
    ::CIAO::Session_Container_ptr c,
    const char * ins_name)
  {
    ::Inherited::CCM_Derived_2_comp_var x =
      ::Inherited::CCM_Derived_2_comp::_narrow (p);

    ::PortableServer::Servant retval = 0;
    if (! ::CORBA::is_nil (x.in ()))
      {
        ACE_NEW_NORETURN (retval,
                          Derived_2_comp_Servant (
                            x.in (),
                            ::Components::CCMHome::_nil (),
                            ins_name,
                            0,
                            c));
      }

    return retval;
  }
}
