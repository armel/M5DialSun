// Copyright (c) F4HWN Armel. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.

// Wifi callback On
void callbackWifiOn(WiFiEvent_t event, WiFiEventInfo_t info) {
  wifiConnected = true;
  Serial.println("Wifi Client Connected");
}

// Wifi callback Got IP
void callbackWifiGotIP(WiFiEvent_t event, WiFiEventInfo_t info) {
  Serial.println(WiFi.localIP());
}

// Wifi callback Off
void callbackWifiOff(WiFiEvent_t event, WiFiEventInfo_t info) {
  wifiConnected = false;
  Serial.println("Wifi Client Disconnected");

  WiFi.begin(myConfig.wifiSSID, myConfig.wifiPassword);
}

// Get local time
void setLocalTime() {
  char timeStringBuff[32];  // 32 chars should be enough
  int h, m, s, Y, M, D;

  struct tm timeinfo;

  M5Dial.Display.setFont(&DroidSansMono6pt7b);
  M5Dial.Display.setTextColor(TFT_WHITE);
  M5Dial.Display.setTextDatum(CC_DATUM);
  M5Dial.Display.drawString("Local time synchronization", 120, 145);
  while (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    delay(1000);
  }

  strftime(timeStringBuff, sizeof(timeStringBuff), "%H:%M:%S %Y/%m/%d", &timeinfo);
  sscanf(timeStringBuff, "%d:%d:%d %d/%d/%d", &h, &m, &s, &Y, &M, &D);

  M5_LOGI("%d:%d:%d %d/%d/%d\n", h, m, s, D, M, Y);

  rtc.setTime(s, m, h, D, M, Y);
}