// Copyright (c) F4HWN Armel. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.

#include "M5DialSun.h"
#include "font.h"
#include "functions.h"

void setup(void) {
  auto cfg = M5.config();
  M5Dial.begin(cfg, true, false);

  Serial.begin(115200);

  // Credit
  M5Dial.Display.setFont(&DroidSansMono6pt7b);
  M5Dial.Display.setTextColor(TFT_WHITE);
  M5Dial.Display.setTextDatum(CC_DATUM);
  M5Dial.Display.drawString(String(NAME) + " " + String(VERSION), 120, 95);
  M5Dial.Display.drawString("By " + String(AUTHOR), 120, 110);

  // Set Wifi
  WiFi.onEvent(callbackWifiOn, ARDUINO_EVENT_WIFI_STA_CONNECTED);
  WiFi.onEvent(callbackWifiGotIP, ARDUINO_EVENT_WIFI_STA_GOT_IP);
  WiFi.onEvent(callbackWifiOff, ARDUINO_EVENT_WIFI_STA_DISCONNECTED);

  while (true) {
    uint8_t attempt = 1;
    WiFi.begin(myConfig.wifiSSID, myConfig.wifiPassword);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      attempt++;
      if (attempt > 10) {
        break;
      }
    }
    if (WiFi.status() == WL_CONNECTED) {
      break;
    }
  }

  M5Dial.Display.setFont(&DroidSansMono6pt7b);
  M5Dial.Display.setTextColor(TFT_WHITE);
  M5Dial.Display.setTextDatum(CC_DATUM);
  M5Dial.Display.drawString(String(WiFi.localIP().toString().c_str()), 120, 130);

  // Set clock
  M5_LOGI("Set local time");
  configTzTime(myConfig.timeTimeZone, myConfig.timeServer);
  setLocalTime();
  viewClock = true;

  // Set sprite
  photoSprite.setColorDepth(16);
  photoSprite.createSprite(240, 240);
}

void loop() {
  M5Dial.update();
  newPosition = M5Dial.Encoder.read();

  if (M5Dial.BtnA.wasPressed()) {
    if (viewClock == true) {
      viewClock = false;
      change    = true;
    } else {
      viewClock = true;
    }
  }

  // Check rotator
  if (newPosition != oldPosition) {
    if (newPosition > oldPosition) {
      current += 1;
    } else if (newPosition < oldPosition) {
      current -= 1;
    }

    if (current < 0) {
      current = limit - 1;
    } else if (current == limit) {
      current = 0;
    }

    oldPosition = newPosition;

    M5_LOGI("%d %d %d %d", newPosition, current, limit, viewClock);

    M5Dial.Speaker.tone(8000, 20);

    photoSprite.drawPngUrl(endpointNasa + "/" + photo[current] + ".png", 0, 0);
    photoSprite.pushSprite(0, 0);
  }

  if (viewClock == true) {
    String tmp = rtc.getTime("%H:%M:%S");
    if (tmp != last) {
      last = tmp;
      timeSprite.deleteSprite();
      timeSprite.setColorDepth(2);
      timeSprite.createSprite(127, 20);
      timeSprite.setFont(&stencilie16pt7b);
      timeSprite.setTextDatum(CC_DATUM);
      timeSprite.drawString(tmp, 64, 10);
      timeSprite.pushSprite(&photoSprite, 56, 20);

      legendSprite.deleteSprite();
      legendSprite.setColorDepth(2);
      legendSprite.createSprite(240, 20);
      legendSprite.setFont(&DroidSansMono6pt7b);
      legendSprite.setTextDatum(CC_DATUM);
      legendSprite.drawString(legend[current], 120, 5);
      legendSprite.pushSprite(&photoSprite, 0, 200, TFT_TRANSPARENT);

      photoSprite.pushSprite(0, 0);
      M5_LOGI("Clock on");
    }
  } else {
    if (change == true) {
      photoSprite.drawPngUrl(endpointNasa + "/" + photo[current] + ".png", 0, 0);
      photoSprite.pushSprite(0, 0);
      change = false;
      M5_LOGI("Clock off");
    }
  }
}