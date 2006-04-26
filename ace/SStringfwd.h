// -*- C++ -*-

//=============================================================================
/**
 *  @file    SStringfwd.h
 *
 *  $Id$
 *
 *  Forward declarations and typedefs of ACE string types.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 *  @author Ossama Othman <ossama@uci.edu>
 */
//=============================================================================

#ifndef ACE_SSTRINGFWD_H
#define ACE_SSTRINGFWD_H

#include /**/ "ace/pre.h"

#include "ace/Basic_Types.h"   /* wchar_t definition */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class CHAR> class ACE_String_Base;  // Forward declaration.

typedef wchar_t ACE_WSTRING_TYPE;

typedef ACE_String_Base<char> ACE_CString;
typedef ACE_String_Base<ACE_WSTRING_TYPE> ACE_WString;

// This allows one to use W or C String based on the Unicode
// setting
#if defined (ACE_USES_WCHAR)
typedef ACE_WString ACE_TString;
#else /* ACE_USES_WCHAR */
typedef ACE_CString ACE_TString;
#endif /* ACE_USES_WCHAR */

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif  /* ACE_SSTRINGFWD_H */
