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
// $hash=7c99d523bab3fd5cff066ead562e4802e0d72bf7$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_VIEWS_MENU_BUTTON_PRESSED_LOCK_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_VIEWS_MENU_BUTTON_PRESSED_LOCK_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/views/cef_menu_button_capi.h"
#include "include/capi/views/cef_menu_button_delegate_capi.h"
#include "include/views/cef_menu_button.h"
#include "include/views/cef_menu_button_delegate.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefMenuButtonPressedLockCppToC
    : public CefCppToCRefCounted<CefMenuButtonPressedLockCppToC,
                                 CefMenuButtonPressedLock,
                                 cef_menu_button_pressed_lock_t> {
 public:
  CefMenuButtonPressedLockCppToC();
  virtual ~CefMenuButtonPressedLockCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_VIEWS_MENU_BUTTON_PRESSED_LOCK_CPPTOC_H_
