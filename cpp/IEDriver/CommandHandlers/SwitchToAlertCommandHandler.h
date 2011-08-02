// Copyright 2011 WebDriver committers
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef WEBDRIVER_IE_SWITCHTOALERTCOMMANDHANDLER_H_
#define WEBDRIVER_IE_SWITCHTOALERTCOMMANDHANDLER_H_

#include "../Browser.h"
#include "../IECommandHandler.h"
#include "../IECommandExecutor.h"

namespace webdriver {

class SwitchToAlertCommandHandler : public IECommandHandler {
public:
 SwitchToAlertCommandHandler(void) {
 }

 virtual ~SwitchToAlertCommandHandler(void) {
 }

protected:
 void SwitchToAlertCommandHandler::ExecuteInternal(const IECommandExecutor& executor, const LocatorMap& locator_parameters, const ParametersMap& command_parameters, Response * response) {
   BrowserHandle browser_wrapper;
   executor.GetCurrentBrowser(&browser_wrapper);
   // This sleep is required to give IE time to draw the dialog.
   ::Sleep(100);
   HWND alert_handle = browser_wrapper->GetActiveDialogWindowHandle();
   if (alert_handle == NULL) {
     response->SetErrorResponse(EMODALDIALOGOPEN, "No alert is active");
   } else {
     response->SetSuccessResponse(Json::Value::null);
   }
 }
};

} // namespace webdriver

#endif // WEBDRIVER_IE_SWITCHTOALERTCOMMANDHANDLER_H_