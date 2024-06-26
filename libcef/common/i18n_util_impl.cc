// Copyright 2021 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that can
// be found in the LICENSE file.

#include "base/i18n/rtl.h"
#include "cef/include/cef_i18n_util.h"

bool CefIsRTL() {
  return base::i18n::IsRTL();
}
