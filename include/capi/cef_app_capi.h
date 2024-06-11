// Copyright (c) 2024 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=dfa0d4d2da319b2fd5e92324fd14301b500ceb5c$
//

#ifndef CEF_INCLUDE_CAPI_CEF_APP_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_APP_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"
#include "include/capi/cef_browser_process_handler_capi.h"
#include "include/capi/cef_command_line_capi.h"
#include "include/capi/cef_render_process_handler_capi.h"
#include "include/capi/cef_resource_bundle_handler_capi.h"
#include "include/capi/cef_scheme_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_app_t;

///
/// Implement this structure to provide handler implementations. Methods will be
/// called by the process and/or thread indicated.
///
typedef struct _cef_app_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Provides an opportunity to view and/or modify command-line arguments
  /// before processing by CEF and Chromium. The |process_type| value will be
  /// NULL for the browser process. Do not keep a reference to the
  /// cef_command_line_t object passed to this function. The
  /// cef_settings_t.command_line_args_disabled value can be used to start with
  /// an NULL command-line object. Any values specified in CefSettings that
  /// equate to command-line arguments will be set before this function is
  /// called. Be cautious when using this function to modify command-line
  /// arguments for non-browser processes as this may result in undefined
  /// behavior including crashes.
  ///
  void(CEF_CALLBACK* on_before_command_line_processing)(
      struct _cef_app_t* self,
      const cef_string_t* process_type,
      struct _cef_command_line_t* command_line);

  ///
  /// Provides an opportunity to register custom schemes. Do not keep a
  /// reference to the |registrar| object. This function is called on the main
  /// thread for each process and the registered schemes should be the same
  /// across all processes.
  ///
  void(CEF_CALLBACK* on_register_custom_schemes)(
      struct _cef_app_t* self,
      struct _cef_scheme_registrar_t* registrar);

  ///
  /// Return the handler for resource bundle events. If
  /// cef_settings_t.pack_loading_disabled is true (1) a handler must be
  /// returned. If no handler is returned resources will be loaded from pack
  /// files. This function is called by the browser and render processes on
  /// multiple threads.
  ///
  struct _cef_resource_bundle_handler_t*(
      CEF_CALLBACK* get_resource_bundle_handler)(struct _cef_app_t* self);

  ///
  /// Return the handler for functionality specific to the browser process. This
  /// function is called on multiple threads in the browser process.
  ///
  struct _cef_browser_process_handler_t*(
      CEF_CALLBACK* get_browser_process_handler)(struct _cef_app_t* self);

  ///
  /// Return the handler for functionality specific to the render process. This
  /// function is called on the render process main thread.
  ///
  struct _cef_render_process_handler_t*(
      CEF_CALLBACK* get_render_process_handler)(struct _cef_app_t* self);
} cef_app_t;

///
/// This function should be called from the application entry point function to
/// execute a secondary process. It can be used to run secondary processes from
/// the browser client executable (default behavior) or from a separate
/// executable specified by the cef_settings_t.browser_subprocess_path value. If
/// called for the browser process (identified by no "type" command-line value)
/// it will return immediately with a value of -1. If called for a recognized
/// secondary process it will block until the process should exit and then
/// return the process exit code. The |application| parameter may be NULL. The
/// |windows_sandbox_info| parameter is only used on Windows and may be NULL
/// (see cef_sandbox_win.h for details).
///
CEF_EXPORT int cef_execute_process(const cef_main_args_t* args,
                                   cef_app_t* application,
                                   void* windows_sandbox_info);

///
/// This function should be called on the main application thread to initialize
/// the CEF browser process. The |application| parameter may be NULL. Returns
/// true (1) if initialization succeeds. Returns false (0) if initialization
/// fails or if early exit is desired (for example, due to process singleton
/// relaunch behavior). If this function returns false (0) then the application
/// should exit immediately without calling any other CEF functions except,
/// optionally, CefGetErrorCode. The |windows_sandbox_info| parameter is only
/// used on Windows and may be NULL (see cef_sandbox_win.h for details).
///
CEF_EXPORT int cef_initialize(const cef_main_args_t* args,
                              const struct _cef_settings_t* settings,
                              cef_app_t* application,
                              void* windows_sandbox_info);

///
/// This function can optionally be called on the main application thread after
/// CefInitialize to retrieve the initialization exit code. When CefInitialize
/// returns true (1) the exit code will be 0 (CEF_RESULT_CODE_NORMAL_EXIT).
/// Otherwise, see cef_resultcode_t for possible exit code values including
/// browser process initialization errors and normal early exit conditions (such
/// as CEF_RESULT_CODE_NORMAL_EXIT_PROCESS_NOTIFIED for process singleton
/// relaunch behavior).
///
CEF_EXPORT int cef_get_exit_code(void);

///
/// This function should be called on the main application thread to shut down
/// the CEF browser process before the application exits. Do not call any other
/// CEF functions after calling this function.
///
CEF_EXPORT void cef_shutdown(void);

///
/// Perform a single iteration of CEF message loop processing. This function is
/// provided for cases where the CEF message loop must be integrated into an
/// existing application message loop. Use of this function is not recommended
/// for most users; use either the cef_run_message_loop() function or
/// cef_settings_t.multi_threaded_message_loop if possible. When using this
/// function care must be taken to balance performance against excessive CPU
/// usage. It is recommended to enable the cef_settings_t.external_message_pump
/// option when using this function so that
/// cef_browser_process_handler_t::on_schedule_message_pump_work() callbacks can
/// facilitate the scheduling process. This function should only be called on
/// the main application thread and only if cef_initialize() is called with a
/// cef_settings_t.multi_threaded_message_loop value of false (0). This function
/// will not block.
///
CEF_EXPORT void cef_do_message_loop_work(void);

///
/// Run the CEF message loop. Use this function instead of an application-
/// provided message loop to get the best balance between performance and CPU
/// usage. This function should only be called on the main application thread
/// and only if cef_initialize() is called with a
/// cef_settings_t.multi_threaded_message_loop value of false (0). This function
/// will block until a quit message is received by the system.
///
CEF_EXPORT void cef_run_message_loop(void);

///
/// Quit the CEF message loop that was started by calling
/// cef_run_message_loop(). This function should only be called on the main
/// application thread and only if cef_run_message_loop() was used.
///
CEF_EXPORT void cef_quit_message_loop(void);

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_APP_CAPI_H_
