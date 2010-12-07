// Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing static and
// virtual method implementations. See the translator.README.txt file in the
// tools directory for more information.
//

#include "libcef_dll/ctocpp/download_handler_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

bool CefDownloadHandlerCToCpp::ReceivedData(void* data, int data_size)
{
  if(CEF_MEMBER_MISSING(struct_, received_data))
    return false;

  return struct_->received_data(struct_, data, data_size) ? true : false;
}

void CefDownloadHandlerCToCpp::Complete()
{
  if(CEF_MEMBER_MISSING(struct_, complete))
    return;

  return struct_->complete(struct_);
}


#ifdef _DEBUG
template<> long CefCToCpp<CefDownloadHandlerCToCpp, CefDownloadHandler,
    cef_download_handler_t>::DebugObjCt = 0;
#endif

