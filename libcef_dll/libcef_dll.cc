// Copyright (c) 2012 The Chromium Embedded Framework Authors. All rights
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
#include "libcef_dll/cpptoc/domdocument_cpptoc.h"
#include "libcef_dll/cpptoc/domevent_cpptoc.h"
#include "libcef_dll/cpptoc/domnode_cpptoc.h"
#include "libcef_dll/cpptoc/drag_data_cpptoc.h"
#include "libcef_dll/cpptoc/frame_cpptoc.h"
#include "libcef_dll/cpptoc/post_data_cpptoc.h"
#include "libcef_dll/cpptoc/post_data_element_cpptoc.h"
#include "libcef_dll/cpptoc/request_cpptoc.h"
#include "libcef_dll/cpptoc/response_cpptoc.h"
#include "libcef_dll/cpptoc/scheme_handler_callback_cpptoc.h"
#include "libcef_dll/cpptoc/stream_reader_cpptoc.h"
#include "libcef_dll/cpptoc/stream_writer_cpptoc.h"
#include "libcef_dll/cpptoc/v8context_cpptoc.h"
#include "libcef_dll/cpptoc/v8exception_cpptoc.h"
#include "libcef_dll/cpptoc/v8value_cpptoc.h"
#include "libcef_dll/cpptoc/web_urlrequest_cpptoc.h"
#include "libcef_dll/cpptoc/xml_reader_cpptoc.h"
#include "libcef_dll/cpptoc/zip_reader_cpptoc.h"
#include "libcef_dll/ctocpp/app_ctocpp.h"
#include "libcef_dll/ctocpp/content_filter_ctocpp.h"
#include "libcef_dll/ctocpp/cookie_visitor_ctocpp.h"
#include "libcef_dll/ctocpp/domevent_listener_ctocpp.h"
#include "libcef_dll/ctocpp/domvisitor_ctocpp.h"
#include "libcef_dll/ctocpp/display_handler_ctocpp.h"
#include "libcef_dll/ctocpp/download_handler_ctocpp.h"
#include "libcef_dll/ctocpp/drag_handler_ctocpp.h"
#include "libcef_dll/ctocpp/find_handler_ctocpp.h"
#include "libcef_dll/ctocpp/focus_handler_ctocpp.h"
#include "libcef_dll/ctocpp/jsdialog_handler_ctocpp.h"
#include "libcef_dll/ctocpp/keyboard_handler_ctocpp.h"
#include "libcef_dll/ctocpp/life_span_handler_ctocpp.h"
#include "libcef_dll/ctocpp/load_handler_ctocpp.h"
#include "libcef_dll/ctocpp/menu_handler_ctocpp.h"
#include "libcef_dll/ctocpp/permission_handler_ctocpp.h"
#include "libcef_dll/ctocpp/print_handler_ctocpp.h"
#include "libcef_dll/ctocpp/proxy_handler_ctocpp.h"
#include "libcef_dll/ctocpp/read_handler_ctocpp.h"
#include "libcef_dll/ctocpp/render_handler_ctocpp.h"
#include "libcef_dll/ctocpp/request_handler_ctocpp.h"
#include "libcef_dll/ctocpp/scheme_handler_ctocpp.h"
#include "libcef_dll/ctocpp/scheme_handler_factory_ctocpp.h"
#include "libcef_dll/ctocpp/storage_visitor_ctocpp.h"
#include "libcef_dll/ctocpp/task_ctocpp.h"
#include "libcef_dll/ctocpp/v8accessor_ctocpp.h"
#include "libcef_dll/ctocpp/v8context_handler_ctocpp.h"
#include "libcef_dll/ctocpp/v8handler_ctocpp.h"
#include "libcef_dll/ctocpp/web_urlrequest_client_ctocpp.h"
#include "libcef_dll/ctocpp/write_handler_ctocpp.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT int cef_initialize(const struct _cef_settings_t* settings,
    struct _cef_app_t* application)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: settings; type: struct_byref_const
  DCHECK(settings);
  if (!settings)
    return 0;
  // Unverified params: application

  // Translate param: settings; type: struct_byref_const
  CefSettings settingsObj;
  if (settings)
    settingsObj.Set(*settings, false);

  // Execute
  bool _retval = CefInitialize(
      settingsObj,
      CefAppCToCpp::Wrap(application));

  // Return type: bool
  return _retval;
}


CEF_EXPORT void cef_shutdown()
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefShutdown();

#ifndef NDEBUG
  // Check that all wrapper objects have been destroyed
  DCHECK(CefBrowserCppToC::DebugObjCt == 0);
  DCHECK(CefContentFilterCToCpp::DebugObjCt == 0);
  DCHECK(CefCookieVisitorCToCpp::DebugObjCt == 0);
  DCHECK(CefDOMDocumentCppToC::DebugObjCt == 0);
  DCHECK(CefDOMEventCppToC::DebugObjCt == 0);
  DCHECK(CefDOMEventListenerCToCpp::DebugObjCt == 0);
  DCHECK(CefDOMNodeCppToC::DebugObjCt == 0);
  DCHECK(CefDOMVisitorCToCpp::DebugObjCt == 0);
  DCHECK(CefDisplayHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefDownloadHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefDragDataCppToC::DebugObjCt == 0);
  DCHECK(CefDragHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefFindHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefFocusHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefFrameCppToC::DebugObjCt == 0);
  DCHECK(CefJSDialogHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefKeyboardHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefLifeSpanHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefLoadHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefMenuHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefPermissionHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefPostDataCppToC::DebugObjCt == 0);
  DCHECK(CefPostDataElementCppToC::DebugObjCt == 0);
  DCHECK(CefPrintHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefProxyHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefReadHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefRenderHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefRequestCppToC::DebugObjCt == 0);
  DCHECK(CefRequestHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefResponseCppToC::DebugObjCt == 0);
  DCHECK(CefSchemeHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefSchemeHandlerCallbackCppToC::DebugObjCt == 0);
  DCHECK(CefSchemeHandlerFactoryCToCpp::DebugObjCt == 0);
  DCHECK(CefStorageVisitorCToCpp::DebugObjCt == 0);
  DCHECK(CefStreamReaderCppToC::DebugObjCt == 0);
  DCHECK(CefStreamWriterCppToC::DebugObjCt == 0);
  DCHECK(CefTaskCToCpp::DebugObjCt == 0);
  DCHECK(CefV8AccessorCToCpp::DebugObjCt == 0);
  DCHECK(CefV8ContextCppToC::DebugObjCt == 0);
  DCHECK(CefV8ContextHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefV8ExceptionCppToC::DebugObjCt == 0);
  DCHECK(CefV8HandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefV8ValueCppToC::DebugObjCt == 0);
  DCHECK(CefWebURLRequestClientCToCpp::DebugObjCt == 0);
  DCHECK(CefWebURLRequestCppToC::DebugObjCt == 0);
  DCHECK(CefWriteHandlerCToCpp::DebugObjCt == 0);
  DCHECK(CefXmlReaderCppToC::DebugObjCt == 0);
  DCHECK(CefZipReaderCppToC::DebugObjCt == 0);
#endif // !NDEBUG
}


CEF_EXPORT void cef_do_message_loop_work()
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefDoMessageLoopWork();
}


CEF_EXPORT void cef_run_message_loop()
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefRunMessageLoop();
}


CEF_EXPORT void cef_quit_message_loop()
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefQuitMessageLoop();
}


CEF_EXPORT int cef_register_extension(const cef_string_t* extension_name,
    const cef_string_t* javascript_code, struct _cef_v8handler_t* handler)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: extension_name; type: string_byref_const
  DCHECK(extension_name);
  if (!extension_name)
    return 0;
  // Verify param: javascript_code; type: string_byref_const
  DCHECK(javascript_code);
  if (!javascript_code)
    return 0;
  // Unverified params: handler

  // Execute
  bool _retval = CefRegisterExtension(
      CefString(extension_name),
      CefString(javascript_code),
      CefV8HandlerCToCpp::Wrap(handler));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_register_custom_scheme(const cef_string_t* scheme_name,
    int is_standard, int is_local, int is_display_isolated)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: scheme_name; type: string_byref_const
  DCHECK(scheme_name);
  if (!scheme_name)
    return 0;

  // Execute
  bool _retval = CefRegisterCustomScheme(
      CefString(scheme_name),
      is_standard?true:false,
      is_local?true:false,
      is_display_isolated?true:false);

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_register_scheme_handler_factory(
    const cef_string_t* scheme_name, const cef_string_t* domain_name,
    struct _cef_scheme_handler_factory_t* factory)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: scheme_name; type: string_byref_const
  DCHECK(scheme_name);
  if (!scheme_name)
    return 0;
  // Unverified params: domain_name, factory

  // Execute
  bool _retval = CefRegisterSchemeHandlerFactory(
      CefString(scheme_name),
      CefString(domain_name),
      CefSchemeHandlerFactoryCToCpp::Wrap(factory));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_clear_scheme_handler_factories()
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  bool _retval = CefClearSchemeHandlerFactories();

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_add_cross_origin_whitelist_entry(
    const cef_string_t* source_origin, const cef_string_t* target_protocol,
    const cef_string_t* target_domain, int allow_target_subdomains)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: source_origin; type: string_byref_const
  DCHECK(source_origin);
  if (!source_origin)
    return 0;
  // Verify param: target_protocol; type: string_byref_const
  DCHECK(target_protocol);
  if (!target_protocol)
    return 0;
  // Verify param: target_domain; type: string_byref_const
  DCHECK(target_domain);
  if (!target_domain)
    return 0;

  // Execute
  bool _retval = CefAddCrossOriginWhitelistEntry(
      CefString(source_origin),
      CefString(target_protocol),
      CefString(target_domain),
      allow_target_subdomains?true:false);

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_remove_cross_origin_whitelist_entry(
    const cef_string_t* source_origin, const cef_string_t* target_protocol,
    const cef_string_t* target_domain, int allow_target_subdomains)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: source_origin; type: string_byref_const
  DCHECK(source_origin);
  if (!source_origin)
    return 0;
  // Verify param: target_protocol; type: string_byref_const
  DCHECK(target_protocol);
  if (!target_protocol)
    return 0;
  // Verify param: target_domain; type: string_byref_const
  DCHECK(target_domain);
  if (!target_domain)
    return 0;

  // Execute
  bool _retval = CefRemoveCrossOriginWhitelistEntry(
      CefString(source_origin),
      CefString(target_protocol),
      CefString(target_domain),
      allow_target_subdomains?true:false);

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_clear_cross_origin_whitelist()
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  bool _retval = CefClearCrossOriginWhitelist();

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_currently_on(cef_thread_id_t threadId)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  bool _retval = CefCurrentlyOn(
      threadId);

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_post_task(cef_thread_id_t threadId, struct _cef_task_t* task)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: task; type: refptr_diff
  DCHECK(task);
  if (!task)
    return 0;

  // Execute
  bool _retval = CefPostTask(
      threadId,
      CefTaskCToCpp::Wrap(task));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_post_delayed_task(cef_thread_id_t threadId,
    struct _cef_task_t* task, long delay_ms)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: task; type: refptr_diff
  DCHECK(task);
  if (!task)
    return 0;

  // Execute
  bool _retval = CefPostDelayedTask(
      threadId,
      CefTaskCToCpp::Wrap(task),
      delay_ms);

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_parse_url(const cef_string_t* url,
    struct _cef_urlparts_t* parts)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return 0;
  // Verify param: parts; type: struct_byref
  DCHECK(parts);
  if (!parts)
    return 0;

  // Translate param: parts; type: struct_byref
  CefURLParts partsObj;
  if (parts)
    partsObj.AttachTo(*parts);

  // Execute
  bool _retval = CefParseURL(
      CefString(url),
      partsObj);

  // Restore param: parts; type: struct_byref
  if (parts)
    partsObj.DetachTo(*parts);

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_create_url(const struct _cef_urlparts_t* parts,
    cef_string_t* url)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: parts; type: struct_byref_const
  DCHECK(parts);
  if (!parts)
    return 0;
  // Verify param: url; type: string_byref
  DCHECK(url);
  if (!url)
    return 0;

  // Translate param: parts; type: struct_byref_const
  CefURLParts partsObj;
  if (parts)
    partsObj.Set(*parts, false);
  // Translate param: url; type: string_byref
  CefString urlStr(url);

  // Execute
  bool _retval = CefCreateURL(
      partsObj,
      urlStr);

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_visit_all_cookies(struct _cef_cookie_visitor_t* visitor)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: visitor; type: refptr_diff
  DCHECK(visitor);
  if (!visitor)
    return 0;

  // Execute
  bool _retval = CefVisitAllCookies(
      CefCookieVisitorCToCpp::Wrap(visitor));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_visit_url_cookies(const cef_string_t* url,
    int includeHttpOnly, struct _cef_cookie_visitor_t* visitor)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return 0;
  // Verify param: visitor; type: refptr_diff
  DCHECK(visitor);
  if (!visitor)
    return 0;

  // Execute
  bool _retval = CefVisitUrlCookies(
      CefString(url),
      includeHttpOnly?true:false,
      CefCookieVisitorCToCpp::Wrap(visitor));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_set_cookie(const cef_string_t* url,
    const struct _cef_cookie_t* cookie)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return 0;
  // Verify param: cookie; type: struct_byref_const
  DCHECK(cookie);
  if (!cookie)
    return 0;

  // Translate param: cookie; type: struct_byref_const
  CefCookie cookieObj;
  if (cookie)
    cookieObj.Set(*cookie, false);

  // Execute
  bool _retval = CefSetCookie(
      CefString(url),
      cookieObj);

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_delete_cookies(const cef_string_t* url,
    const cef_string_t* cookie_name)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: url, cookie_name

  // Execute
  bool _retval = CefDeleteCookies(
      CefString(url),
      CefString(cookie_name));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_set_cookie_path(const cef_string_t* path)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: path

  // Execute
  bool _retval = CefSetCookiePath(
      CefString(path));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_visit_storage(enum cef_storage_type_t type,
    const cef_string_t* origin, const cef_string_t* key,
    struct _cef_storage_visitor_t* visitor)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: visitor; type: refptr_diff
  DCHECK(visitor);
  if (!visitor)
    return 0;
  // Unverified params: origin, key

  // Execute
  bool _retval = CefVisitStorage(
      type,
      CefString(origin),
      CefString(key),
      CefStorageVisitorCToCpp::Wrap(visitor));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_set_storage(enum cef_storage_type_t type,
    const cef_string_t* origin, const cef_string_t* key,
    const cef_string_t* value)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: origin; type: string_byref_const
  DCHECK(origin);
  if (!origin)
    return 0;
  // Verify param: key; type: string_byref_const
  DCHECK(key);
  if (!key)
    return 0;
  // Verify param: value; type: string_byref_const
  DCHECK(value);
  if (!value)
    return 0;

  // Execute
  bool _retval = CefSetStorage(
      type,
      CefString(origin),
      CefString(key),
      CefString(value));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_delete_storage(enum cef_storage_type_t type,
    const cef_string_t* origin, const cef_string_t* key)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: origin, key

  // Execute
  bool _retval = CefDeleteStorage(
      type,
      CefString(origin),
      CefString(key));

  // Return type: bool
  return _retval;
}


CEF_EXPORT int cef_set_storage_path(enum cef_storage_type_t type,
    const cef_string_t* path)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: path

  // Execute
  bool _retval = CefSetStoragePath(
      type,
      CefString(path));

  // Return type: bool
  return _retval;
}


