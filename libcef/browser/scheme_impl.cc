// Copyright (c) 2015 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that can
// be found in the LICENSE file.

#include "base/logging.h"
#include "cef/include/cef_scheme.h"
#include "cef/libcef/browser/context.h"

bool CefRegisterSchemeHandlerFactory(
    const CefString& scheme_name,
    const CefString& domain_name,
    CefRefPtr<CefSchemeHandlerFactory> factory) {
  // Verify that the context is in a valid state.
  if (!CONTEXT_STATE_VALID()) {
    DCHECK(false) << "context not valid";
    return false;
  }

  return CefRequestContext::GetGlobalContext()->RegisterSchemeHandlerFactory(
      scheme_name, domain_name, factory);
}

bool CefClearSchemeHandlerFactories() {
  // Verify that the context is in a valid state.
  if (!CONTEXT_STATE_VALID()) {
    DCHECK(false) << "context not valid";
    return false;
  }

  return CefRequestContext::GetGlobalContext()->ClearSchemeHandlerFactories();
}
