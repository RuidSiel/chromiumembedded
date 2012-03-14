// Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "cefclient/cefclient.h"
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include "include/cef_app.h"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/cef_frame.h"
#include "include/cef_runnable.h"
#include "cefclient/cefclient_switches.h"
#include "cefclient/client_handler.h"
#include "cefclient/string_util.h"
#include "cefclient/util.h"

namespace {

// Return the int representation of the specified string.
int GetIntValue(const CefString& str) {
  if (str.empty())
    return 0;

  std::string stdStr = str;
  return atoi(stdStr.c_str());
}

// ClientApp implementation.
class ClientApp : public CefApp,
                  public CefProxyHandler {
 public:
  ClientApp(cef_proxy_type_t proxy_type, const CefString& proxy_config)
    : proxy_type_(proxy_type),
      proxy_config_(proxy_config) {
  }

  // CefApp methods
  virtual CefRefPtr<CefProxyHandler> GetProxyHandler() OVERRIDE { return this; }

  // CefProxyHandler methods
  virtual void GetProxyForUrl(const CefString& url,
                              CefProxyInfo& proxy_info) OVERRIDE {
    proxy_info.proxyType = proxy_type_;
    if (!proxy_config_.empty())
      CefString(&proxy_info.proxyList) = proxy_config_;
  }

 protected:
  cef_proxy_type_t proxy_type_;
  CefString proxy_config_;

  IMPLEMENT_REFCOUNTING(ClientApp);
};

}  // namespace

CefRefPtr<ClientHandler> g_handler;
CefRefPtr<CefCommandLine> g_command_line;

CefRefPtr<CefBrowser> AppGetBrowser() {
  if (!g_handler.get())
    return NULL;
  return g_handler->GetBrowser();
}

CefWindowHandle AppGetMainHwnd() {
  if (!g_handler.get())
    return NULL;
  return g_handler->GetMainHwnd();
}

void AppInitCommandLine(int argc, const char* const* argv) {
  g_command_line = CefCommandLine::CreateCommandLine();
#if defined(OS_WIN)
  g_command_line->InitFromString(::GetCommandLineW());
#else
  g_command_line->InitFromArgv(argc, argv);
#endif
}

// Returns the application command line object.
CefRefPtr<CefCommandLine> AppGetCommandLine() {
  return g_command_line;
}

// Returns the application settings based on command line arguments.
void AppGetSettings(CefSettings& settings, CefRefPtr<CefApp>& app) {
  ASSERT(g_command_line.get());
  if (!g_command_line.get())
    return;

  CefString str;

#if defined(OS_WIN)
  settings.multi_threaded_message_loop =
      g_command_line->HasSwitch(cefclient::kMultiThreadedMessageLoop);
#endif

  CefString(&settings.cache_path) =
      g_command_line->GetSwitchValue(cefclient::kCachePath);
  CefString(&settings.log_file) =
      g_command_line->GetSwitchValue(cefclient::kLogFile);

  {
    std::string str = g_command_line->GetSwitchValue(cefclient::kLogSeverity);
    bool invalid = false;
    if (!str.empty()) {
      if (str == cefclient::kLogSeverity_Verbose)
        settings.log_severity = LOGSEVERITY_VERBOSE;
      else if (str == cefclient::kLogSeverity_Info)
        settings.log_severity = LOGSEVERITY_INFO;
      else if (str == cefclient::kLogSeverity_Warning)
        settings.log_severity = LOGSEVERITY_WARNING;
      else if (str == cefclient::kLogSeverity_Error)
        settings.log_severity = LOGSEVERITY_ERROR;
      else if (str == cefclient::kLogSeverity_ErrorReport)
        settings.log_severity = LOGSEVERITY_ERROR_REPORT;
      else if (str == cefclient::kLogSeverity_Disable)
        settings.log_severity = LOGSEVERITY_DISABLE;
      else
        invalid = true;
    }
    if (str.empty() || invalid) {
#ifdef NDEBUG
      // Only log error messages and higher in release build.
      settings.log_severity = LOGSEVERITY_ERROR;
#endif
    }
  }

  {
    std::string str = g_command_line->GetSwitchValue(cefclient::kGraphicsImpl);
    if (!str.empty()) {
#if defined(OS_WIN)
      if (str == cefclient::kGraphicsImpl_Angle)
        settings.graphics_implementation = ANGLE_IN_PROCESS;
      else if (str == cefclient::kGraphicsImpl_AngleCmdBuffer)
        settings.graphics_implementation = ANGLE_IN_PROCESS_COMMAND_BUFFER;
      else
#endif
      if (str == cefclient::kGraphicsImpl_Desktop)
        settings.graphics_implementation = DESKTOP_IN_PROCESS;
      else if (str == cefclient::kGraphicsImpl_DesktopCmdBuffer)
        settings.graphics_implementation = DESKTOP_IN_PROCESS_COMMAND_BUFFER;
    }
  }

  settings.local_storage_quota = GetIntValue(
      g_command_line->GetSwitchValue(cefclient::kLocalStorageQuota));
  settings.session_storage_quota = GetIntValue(
      g_command_line->GetSwitchValue(cefclient::kSessionStorageQuota));

  CefString(&settings.javascript_flags) =
      g_command_line->GetSwitchValue(cefclient::kJavascriptFlags);

  // Retrieve command-line proxy configuration, if any.
  bool has_proxy = false;
  cef_proxy_type_t proxy_type = PROXY_TYPE_DIRECT;
  CefString proxy_config;

  if (g_command_line->HasSwitch(cefclient::kProxyType)) {
    std::string str = g_command_line->GetSwitchValue(cefclient::kProxyType);
    if (str == cefclient::kProxyType_Direct) {
      has_proxy = true;
      proxy_type = PROXY_TYPE_DIRECT;
    } else if (str == cefclient::kProxyType_Named ||
               str == cefclient::kProxyType_Pac) {
      proxy_config = g_command_line->GetSwitchValue(cefclient::kProxyConfig);
      if (!proxy_config.empty()) {
        has_proxy = true;
        proxy_type = (str == cefclient::kProxyType_Named?
                      PROXY_TYPE_NAMED:PROXY_TYPE_PAC_STRING);
      }
    }
  }

  if (has_proxy) {
    // Provide a ClientApp instance to handle proxy resolution.
    app = new ClientApp(proxy_type, proxy_config);
  }
}

// Returns the application browser settings based on command line arguments.
void AppGetBrowserSettings(CefBrowserSettings& settings) {
  ASSERT(g_command_line.get());
  if (!g_command_line.get())
    return;

  settings.drag_drop_disabled =
      g_command_line->HasSwitch(cefclient::kDragDropDisabled);
  settings.load_drops_disabled =
      g_command_line->HasSwitch(cefclient::kLoadDropsDisabled);
  settings.history_disabled =
      g_command_line->HasSwitch(cefclient::kHistoryDisabled);
  settings.remote_fonts_disabled =
      g_command_line->HasSwitch(cefclient::kRemoteFontsDisabled);

  CefString(&settings.default_encoding) =
      g_command_line->GetSwitchValue(cefclient::kDefaultEncoding);

  settings.encoding_detector_enabled =
      g_command_line->HasSwitch(cefclient::kEncodingDetectorEnabled);
  settings.javascript_disabled =
      g_command_line->HasSwitch(cefclient::kJavascriptDisabled);
  settings.javascript_open_windows_disallowed =
      g_command_line->HasSwitch(cefclient::kJavascriptOpenWindowsDisallowed);
  settings.javascript_close_windows_disallowed =
      g_command_line->HasSwitch(cefclient::kJavascriptCloseWindowsDisallowed);
  settings.javascript_access_clipboard_disallowed =
      g_command_line->HasSwitch(
          cefclient::kJavascriptAccessClipboardDisallowed);
  settings.dom_paste_disabled =
      g_command_line->HasSwitch(cefclient::kDomPasteDisabled);
  settings.caret_browsing_enabled =
      g_command_line->HasSwitch(cefclient::kCaretBrowsingDisabled);
  settings.java_disabled =
      g_command_line->HasSwitch(cefclient::kJavaDisabled);
  settings.plugins_disabled =
      g_command_line->HasSwitch(cefclient::kPluginsDisabled);
  settings.universal_access_from_file_urls_allowed =
      g_command_line->HasSwitch(cefclient::kUniversalAccessFromFileUrlsAllowed);
  settings.file_access_from_file_urls_allowed =
      g_command_line->HasSwitch(cefclient::kFileAccessFromFileUrlsAllowed);
  settings.web_security_disabled =
      g_command_line->HasSwitch(cefclient::kWebSecurityDisabled);
  settings.xss_auditor_enabled =
      g_command_line->HasSwitch(cefclient::kXssAuditorEnabled);
  settings.image_load_disabled =
      g_command_line->HasSwitch(cefclient::kImageLoadingDisabled);
  settings.shrink_standalone_images_to_fit =
      g_command_line->HasSwitch(cefclient::kShrinkStandaloneImagesToFit);
  settings.site_specific_quirks_disabled =
      g_command_line->HasSwitch(cefclient::kSiteSpecificQuirksDisabled);
  settings.text_area_resize_disabled =
      g_command_line->HasSwitch(cefclient::kTextAreaResizeDisabled);
  settings.page_cache_disabled =
      g_command_line->HasSwitch(cefclient::kPageCacheDisabled);
  settings.tab_to_links_disabled =
      g_command_line->HasSwitch(cefclient::kTabToLinksDisabled);
  settings.hyperlink_auditing_disabled =
      g_command_line->HasSwitch(cefclient::kHyperlinkAuditingDisabled);
  settings.user_style_sheet_enabled =
      g_command_line->HasSwitch(cefclient::kUserStyleSheetEnabled);

  CefString(&settings.user_style_sheet_location) =
      g_command_line->GetSwitchValue(cefclient::kUserStyleSheetLocation);

  settings.author_and_user_styles_disabled =
      g_command_line->HasSwitch(cefclient::kAuthorAndUserStylesDisabled);
  settings.local_storage_disabled =
      g_command_line->HasSwitch(cefclient::kLocalStorageDisabled);
  settings.databases_disabled =
      g_command_line->HasSwitch(cefclient::kDatabasesDisabled);
  settings.application_cache_disabled =
      g_command_line->HasSwitch(cefclient::kApplicationCacheDisabled);
  settings.webgl_disabled =
      g_command_line->HasSwitch(cefclient::kWebglDisabled);
  settings.accelerated_compositing_disabled =
      g_command_line->HasSwitch(cefclient::kAcceleratedCompositingDisabled);
  settings.threaded_compositing_enabled =
      g_command_line->HasSwitch(cefclient::kThreadedCompositingEnabled);
  settings.accelerated_layers_disabled =
      g_command_line->HasSwitch(cefclient::kAcceleratedLayersDisabled);
  settings.accelerated_video_disabled =
      g_command_line->HasSwitch(cefclient::kAcceleratedVideoDisabled);
  settings.accelerated_2d_canvas_disabled =
      g_command_line->HasSwitch(cefclient::kAcceledated2dCanvasDisabled);
  settings.accelerated_painting_enabled =
      g_command_line->HasSwitch(cefclient::kAcceleratedPaintingEnabled);
  settings.accelerated_filters_enabled =
      g_command_line->HasSwitch(cefclient::kAcceleratedFiltersEnabled);
  settings.accelerated_plugins_disabled =
      g_command_line->HasSwitch(cefclient::kAcceleratedPluginsDisabled);
  settings.developer_tools_disabled =
      g_command_line->HasSwitch(cefclient::kDeveloperToolsDisabled);
  settings.fullscreen_enabled =
      g_command_line->HasSwitch(cefclient::kFullscreenEnabled);
}

void RunGetSourceTest(CefRefPtr<CefBrowser> browser) {
  class Visitor : public CefStringVisitor {
   public:
    Visitor(CefRefPtr<CefBrowser> browser) : browser_(browser) {}
    virtual void Visit(const CefString& string) OVERRIDE {
      std::string source = StringReplace(string, "<", "&lt;");
      source = StringReplace(source, ">", "&gt;");
      std::stringstream ss;
      ss << "<html><body>Source:<pre>" << source << "</pre></body></html>";
      browser_->GetMainFrame()->LoadString(ss.str(), "http://tests/getsource");
    }
   private:
    CefRefPtr<CefBrowser> browser_;
    IMPLEMENT_REFCOUNTING(Visitor);
  };

  browser->GetMainFrame()->GetSource(new Visitor(browser));
}

void RunGetTextTest(CefRefPtr<CefBrowser> browser) {
  class Visitor : public CefStringVisitor {
   public:
    Visitor(CefRefPtr<CefBrowser> browser) : browser_(browser) {}
    virtual void Visit(const CefString& string) OVERRIDE {
      std::string text = StringReplace(string, "<", "&lt;");
      text = StringReplace(text, ">", "&gt;");
      std::stringstream ss;
      ss << "<html><body>Text:<pre>" << text << "</pre></body></html>";
      browser_->GetMainFrame()->LoadString(ss.str(), "http://tests/gettext");
    }
   private:
    CefRefPtr<CefBrowser> browser_;
    IMPLEMENT_REFCOUNTING(Visitor);
  };

  browser->GetMainFrame()->GetText(new Visitor(browser));
}

void RunRequestTest(CefRefPtr<CefBrowser> browser) {
  // Create a new request
  CefRefPtr<CefRequest> request(CefRequest::CreateRequest());

  // Set the request URL
  request->SetURL("http://tests/request");

  // Add post data to the request.  The correct method and content-
  // type headers will be set by CEF.
  CefRefPtr<CefPostDataElement> postDataElement(
      CefPostDataElement::CreatePostDataElement());
  std::string data = "arg1=val1&arg2=val2";
  postDataElement->SetToBytes(data.length(), data.c_str());
  CefRefPtr<CefPostData> postData(CefPostData::CreatePostData());
  postData->AddElement(postDataElement);
  request->SetPostData(postData);

  // Add a custom header
  CefRequest::HeaderMap headerMap;
  headerMap.insert(
      std::make_pair("X-My-Header", "My Header Value"));
  request->SetHeaderMap(headerMap);

  // Load the request
  browser->GetMainFrame()->LoadRequest(request);
}

void RunPopupTest(CefRefPtr<CefBrowser> browser) {
  browser->GetMainFrame()->ExecuteJavaScript(
      "window.open('http://www.google.com');", "about:blank", 0);
}

void RunLocalStorageTest(CefRefPtr<CefBrowser> browser) {
  browser->GetMainFrame()->LoadURL("http://tests/localstorage");
}

void RunAccelerated2DCanvasTest(CefRefPtr<CefBrowser> browser) {
  browser->GetMainFrame()->LoadURL(
      "http://mudcu.be/labs/JS1k/BreathingGalaxies.html");
}

void RunAcceleratedLayersTest(CefRefPtr<CefBrowser> browser) {
  browser->GetMainFrame()->LoadURL(
      "http://webkit.org/blog-files/3d-transforms/poster-circle.html");
}

void RunWebGLTest(CefRefPtr<CefBrowser> browser) {
  browser->GetMainFrame()->LoadURL(
      "http://webglsamples.googlecode.com/hg/field/field.html");
}

void RunHTML5VideoTest(CefRefPtr<CefBrowser> browser) {
  browser->GetMainFrame()->LoadURL(
      "http://www.youtube.com/watch?v=siOHh0uzcuY&html5=True");
}

void RunXMLHTTPRequestTest(CefRefPtr<CefBrowser> browser) {
  browser->GetMainFrame()->LoadURL("http://tests/xmlhttprequest");
}

void RunDragDropTest(CefRefPtr<CefBrowser> browser) {
  browser->GetMainFrame()->LoadURL("http://html5demos.com/drag");
}

void RunGeolocationTest(CefRefPtr<CefBrowser> browser) {
  browser->GetMainFrame()->LoadURL("http://html5demos.com/geo");
}
