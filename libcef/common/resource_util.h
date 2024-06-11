// Copyright 2017 The Chromium Embedded Framework Authors. Portions copyright
// 2011 The Chromium Authors. All rights reserved. Use of this source code is
// governed by a BSD-style license that can be found in the LICENSE file.

#ifndef CEF_LIBCEF_COMMON_RESOURCE_UTIL_H_
#define CEF_LIBCEF_COMMON_RESOURCE_UTIL_H_
#pragma once

#include "cef/include/cef_base.h"
#include "cef/libcef/features/features.h"

#if BUILDFLAG(ENABLE_ALLOY_BOOTSTRAP)
#include "ui/base/resource/resource_scale_factor.h"
#endif

namespace base {
class CommandLine;
#if BUILDFLAG(ENABLE_ALLOY_BOOTSTRAP)
class FilePath;
#endif
}  // namespace base

namespace resource_util {

#if BUILDFLAG(ENABLE_ALLOY_BOOTSTRAP)
// Returns the default path for the debug.log file.
base::FilePath GetDefaultLogFilePath();

// Called from MainDelegate::PreSandboxStartup.
void OverrideDefaultDownloadDir();

// Returns true if |scale_factor| is supported by this platform.
bool IsScaleFactorSupported(ui::ResourceScaleFactor scale_factor);
#endif  // BUILDFLAG(ENABLE_ALLOY_BOOTSTRAP)

// Returns the directory that contains resource files (*.bin, *.dat, *.pak,
// etc).
base::FilePath GetResourcesDir();

void OverrideUserDataDir(CefSettings* settings,
                         const base::CommandLine* command_line);

#if BUILDFLAG(IS_LINUX)
// Look for binary files (*.bin, *.dat, *.pak, chrome-sandbox, libGLESv2.so,
// libEGL.so, locales/*.pak, swiftshader/*.so) next to libcef instead of the exe
// on Linux. This is already the default on Windows.
void OverrideAssetPath();
#endif

}  // namespace resource_util

#endif  // CEF_LIBCEF_COMMON_RESOURCE_UTIL_H_
