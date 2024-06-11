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
// $hash=b2fdb307c4fb62827dec208d14c7fe1c2b82f915$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_RESOLVE_CALLBACK_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_RESOLVE_CALLBACK_CTOCPP_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include <vector>

#include "include/capi/cef_request_context_capi.h"
#include "include/capi/cef_request_context_handler_capi.h"
#include "include/capi/cef_scheme_capi.h"
#include "include/cef_request_context.h"
#include "include/cef_request_context_handler.h"
#include "include/cef_scheme.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefResolveCallbackCToCpp
    : public CefCToCppRefCounted<CefResolveCallbackCToCpp,
                                 CefResolveCallback,
                                 cef_resolve_callback_t> {
 public:
  CefResolveCallbackCToCpp();
  virtual ~CefResolveCallbackCToCpp();

  // CefResolveCallback methods.
  void OnResolveCompleted(cef_errorcode_t result,
                          const std::vector<CefString>& resolved_ips) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_RESOLVE_CALLBACK_CTOCPP_H_