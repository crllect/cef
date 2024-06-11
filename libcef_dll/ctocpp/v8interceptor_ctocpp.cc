// Copyright (c) 2024 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=a4d05b34b629979d9e25b24bd9065294b916702f$
//

#include "libcef_dll/ctocpp/v8interceptor_ctocpp.h"

#include "libcef_dll/cpptoc/v8value_cpptoc.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
bool CefV8InterceptorCToCpp::Get(const CefString& name,
                                 const CefRefPtr<CefV8Value> object,
                                 CefRefPtr<CefV8Value>& retval,
                                 CefString& exception) {
  cef_v8interceptor_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_byname)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return false;
  }
  // Verify param: object; type: refptr_diff
  DCHECK(object.get());
  if (!object.get()) {
    return false;
  }

  // Translate param: retval; type: refptr_diff_byref
  cef_v8value_t* retvalStruct = NULL;
  if (retval.get()) {
    retvalStruct = CefV8ValueCppToC::Wrap(retval);
  }
  cef_v8value_t* retvalOrig = retvalStruct;

  // Execute
  int _retval = _struct->get_byname(
      _struct, name.GetStruct(), CefV8ValueCppToC::Wrap(object), &retvalStruct,
      exception.GetWritableStruct());

  // Restore param:retval; type: refptr_diff_byref
  if (retvalStruct) {
    if (retvalStruct != retvalOrig) {
      retval = CefV8ValueCppToC::Unwrap(retvalStruct);
    }
  } else {
    retval = nullptr;
  }

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8InterceptorCToCpp::Get(int index,
                                 const CefRefPtr<CefV8Value> object,
                                 CefRefPtr<CefV8Value>& retval,
                                 CefString& exception) {
  cef_v8interceptor_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_byindex)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0) {
    return false;
  }
  // Verify param: object; type: refptr_diff
  DCHECK(object.get());
  if (!object.get()) {
    return false;
  }

  // Translate param: retval; type: refptr_diff_byref
  cef_v8value_t* retvalStruct = NULL;
  if (retval.get()) {
    retvalStruct = CefV8ValueCppToC::Wrap(retval);
  }
  cef_v8value_t* retvalOrig = retvalStruct;

  // Execute
  int _retval =
      _struct->get_byindex(_struct, index, CefV8ValueCppToC::Wrap(object),
                           &retvalStruct, exception.GetWritableStruct());

  // Restore param:retval; type: refptr_diff_byref
  if (retvalStruct) {
    if (retvalStruct != retvalOrig) {
      retval = CefV8ValueCppToC::Unwrap(retvalStruct);
    }
  } else {
    retval = nullptr;
  }

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8InterceptorCToCpp::Set(const CefString& name,
                                 const CefRefPtr<CefV8Value> object,
                                 const CefRefPtr<CefV8Value> value,
                                 CefString& exception) {
  cef_v8interceptor_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_byname)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return false;
  }
  // Verify param: object; type: refptr_diff
  DCHECK(object.get());
  if (!object.get()) {
    return false;
  }
  // Verify param: value; type: refptr_diff
  DCHECK(value.get());
  if (!value.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_byname(
      _struct, name.GetStruct(), CefV8ValueCppToC::Wrap(object),
      CefV8ValueCppToC::Wrap(value), exception.GetWritableStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8InterceptorCToCpp::Set(int index,
                                 const CefRefPtr<CefV8Value> object,
                                 const CefRefPtr<CefV8Value> value,
                                 CefString& exception) {
  cef_v8interceptor_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_byindex)) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0) {
    return false;
  }
  // Verify param: object; type: refptr_diff
  DCHECK(object.get());
  if (!object.get()) {
    return false;
  }
  // Verify param: value; type: refptr_diff
  DCHECK(value.get());
  if (!value.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_byindex(
      _struct, index, CefV8ValueCppToC::Wrap(object),
      CefV8ValueCppToC::Wrap(value), exception.GetWritableStruct());

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefV8InterceptorCToCpp::CefV8InterceptorCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefV8InterceptorCToCpp::~CefV8InterceptorCToCpp() {}

template <>
cef_v8interceptor_t*
CefCToCppRefCounted<CefV8InterceptorCToCpp,
                    CefV8Interceptor,
                    cef_v8interceptor_t>::UnwrapDerived(CefWrapperType type,
                                                        CefV8Interceptor* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefV8InterceptorCToCpp,
                                   CefV8Interceptor,
                                   cef_v8interceptor_t>::kWrapperType =
    WT_V8INTERCEPTOR;
