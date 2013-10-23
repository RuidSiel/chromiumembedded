// Copyright (c) 2013 The Chromium Embedded Framework Authors.
// Portions (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/browser/chrome_browser_process_stub.h"
#include "libcef/browser/context.h"

#include "base/memory/scoped_ptr.h"
#include "ui/message_center/message_center.h"

ChromeBrowserProcessStub::ChromeBrowserProcessStub()
  : locale_("en-US") {
}

ChromeBrowserProcessStub::~ChromeBrowserProcessStub() {
  g_browser_process = NULL;
}

void ChromeBrowserProcessStub::ResourceDispatcherHostCreated() {
  NOTIMPLEMENTED();
};

void ChromeBrowserProcessStub::EndSession() {
  NOTIMPLEMENTED();
};

MetricsService* ChromeBrowserProcessStub::metrics_service() {
  NOTIMPLEMENTED();
  return NULL;
}

IOThread* ChromeBrowserProcessStub::io_thread() {
  NOTIMPLEMENTED();
  return NULL;
}

WatchDogThread* ChromeBrowserProcessStub::watchdog_thread() {
  NOTIMPLEMENTED();
  return NULL;
}

ProfileManager* ChromeBrowserProcessStub::profile_manager() {
  NOTIMPLEMENTED();
  return NULL;
}

PrefService* ChromeBrowserProcessStub::local_state() {
  NOTIMPLEMENTED();
  return NULL;
}

net::URLRequestContextGetter*
  ChromeBrowserProcessStub::system_request_context() {
  NOTIMPLEMENTED();
  return NULL;
}

chrome_variations::VariationsService*
  ChromeBrowserProcessStub::variations_service() {
  NOTIMPLEMENTED();
  return NULL;
}

BrowserProcessPlatformPart* ChromeBrowserProcessStub::platform_part() {
  NOTIMPLEMENTED();
  return NULL;
}

extensions::EventRouterForwarder*
    ChromeBrowserProcessStub::extension_event_router_forwarder() {
  NOTIMPLEMENTED();
  return NULL;
}

NotificationUIManager* ChromeBrowserProcessStub::notification_ui_manager() {
  NOTIMPLEMENTED();
  return NULL;
}

message_center::MessageCenter* ChromeBrowserProcessStub::message_center() {
  NOTIMPLEMENTED();
  return NULL;
}

policy::BrowserPolicyConnector*
  ChromeBrowserProcessStub::browser_policy_connector() {
  NOTIMPLEMENTED();
  return NULL;
}

policy::PolicyService* ChromeBrowserProcessStub::policy_service() {
  NOTIMPLEMENTED();
  return NULL;
}

IconManager* ChromeBrowserProcessStub::icon_manager() {
  NOTIMPLEMENTED();
  return NULL;
}

GLStringManager* ChromeBrowserProcessStub::gl_string_manager() {
  NOTIMPLEMENTED();
  return NULL;
}

GpuModeManager* ChromeBrowserProcessStub::gpu_mode_manager() {
  NOTIMPLEMENTED();
  return NULL;
}

RenderWidgetSnapshotTaker*
  ChromeBrowserProcessStub::GetRenderWidgetSnapshotTaker() {
  NOTIMPLEMENTED();
  return NULL;
}

AutomationProviderList*
  ChromeBrowserProcessStub::GetAutomationProviderList() {
  NOTIMPLEMENTED();
  return NULL;
}

void ChromeBrowserProcessStub::CreateDevToolsHttpProtocolHandler(
    chrome::HostDesktopType host_desktop_type,
    const std::string& ip,
    int port,
    const std::string& frontend_url) {
}

unsigned int ChromeBrowserProcessStub::AddRefModule() {
  NOTIMPLEMENTED();
  return 0;
}

unsigned int ChromeBrowserProcessStub::ReleaseModule() {
  NOTIMPLEMENTED();
  return 0;
}

bool ChromeBrowserProcessStub::IsShuttingDown() {
  NOTIMPLEMENTED();
  return false;
}

printing::PrintJobManager* ChromeBrowserProcessStub::print_job_manager() {
  return _Context->print_job_manager();
}

printing::PrintPreviewDialogController*
    ChromeBrowserProcessStub::print_preview_dialog_controller() {
  NOTIMPLEMENTED();
  return NULL;
}

printing::BackgroundPrintingManager*
    ChromeBrowserProcessStub::background_printing_manager() {
  NOTIMPLEMENTED();
  return NULL;
}

IntranetRedirectDetector*
  ChromeBrowserProcessStub::intranet_redirect_detector() {
  NOTIMPLEMENTED();
  return NULL;
}

const std::string &ChromeBrowserProcessStub::GetApplicationLocale() {
  DCHECK(!locale_.empty());
  return locale_;
}

void ChromeBrowserProcessStub::SetApplicationLocale(const std::string& locale) {
  locale_ = locale;
}

DownloadStatusUpdater* ChromeBrowserProcessStub::download_status_updater() {
  NOTIMPLEMENTED();
  return NULL;
}

DownloadRequestLimiter* ChromeBrowserProcessStub::download_request_limiter() {
  NOTIMPLEMENTED();
  return NULL;
}

BackgroundModeManager* ChromeBrowserProcessStub::background_mode_manager() {
  NOTIMPLEMENTED();
  return NULL;
}

StatusTray* ChromeBrowserProcessStub::status_tray() {
  NOTIMPLEMENTED();
  return NULL;
}

SafeBrowsingService* ChromeBrowserProcessStub::safe_browsing_service() {
  NOTIMPLEMENTED();
  return NULL;
}

safe_browsing::ClientSideDetectionService*
    ChromeBrowserProcessStub::safe_browsing_detection_service() {
  NOTIMPLEMENTED();
  return NULL;
}

#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
void ChromeBrowserProcessStub::StartAutoupdateTimer() {
}
#endif

ChromeNetLog* ChromeBrowserProcessStub::net_log() {
  NOTIMPLEMENTED();
  return NULL;
}

prerender::PrerenderTracker* ChromeBrowserProcessStub::prerender_tracker() {
  NOTIMPLEMENTED();
  return NULL;
}

ComponentUpdateService* ChromeBrowserProcessStub::component_updater() {
  NOTIMPLEMENTED();
  return NULL;
}

CRLSetFetcher* ChromeBrowserProcessStub::crl_set_fetcher() {
  NOTIMPLEMENTED();
  return NULL;
}

PnaclComponentInstaller*
  ChromeBrowserProcessStub::pnacl_component_installer() {
  NOTIMPLEMENTED();
  return NULL;
}

BookmarkPromptController*
  ChromeBrowserProcessStub::bookmark_prompt_controller() {
  NOTIMPLEMENTED();
  return NULL;
}

chrome::MediaFileSystemRegistry*
  ChromeBrowserProcessStub::media_file_system_registry() {
  NOTIMPLEMENTED();
  return NULL;
}

bool ChromeBrowserProcessStub::created_local_state() const {
  NOTIMPLEMENTED();
  return false;
}

#if defined(ENABLE_WEBRTC)
WebRtcLogUploader* ChromeBrowserProcessStub::webrtc_log_uploader() {
  NOTIMPLEMENTED();
  return NULL;
}
#endif
