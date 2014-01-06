// Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
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

#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/geolocation_callback_cpptoc.h"
#include "libcef_dll/ctocpp/geolocation_handler_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

void CefGeolocationHandlerCToCpp::OnRequestGeolocationPermission(
    CefRefPtr<CefBrowser> browser, const CefString& requesting_url,
    int request_id, CefRefPtr<CefGeolocationCallback> callback) {
  if (CEF_MEMBER_MISSING(struct_, on_request_geolocation_permission))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Verify param: requesting_url; type: string_byref_const
  DCHECK(!requesting_url.empty());
  if (requesting_url.empty())
    return;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return;

  // Execute
  struct_->on_request_geolocation_permission(struct_,
      CefBrowserCppToC::Wrap(browser),
      requesting_url.GetStruct(),
      request_id,
      CefGeolocationCallbackCppToC::Wrap(callback));
}

void CefGeolocationHandlerCToCpp::OnCancelGeolocationPermission(
    CefRefPtr<CefBrowser> browser, const CefString& requesting_url,
    int request_id) {
  if (CEF_MEMBER_MISSING(struct_, on_cancel_geolocation_permission))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Verify param: requesting_url; type: string_byref_const
  DCHECK(!requesting_url.empty());
  if (requesting_url.empty())
    return;

  // Execute
  struct_->on_cancel_geolocation_permission(struct_,
      CefBrowserCppToC::Wrap(browser),
      requesting_url.GetStruct(),
      request_id);
}


#ifndef NDEBUG
template<> long CefCToCpp<CefGeolocationHandlerCToCpp, CefGeolocationHandler,
    cef_geolocation_handler_t>::DebugObjCt = 0;
#endif

