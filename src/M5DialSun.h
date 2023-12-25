// Copyright (c) F4HWN Armel. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.

#define VERSION "0.0.1"
#define AUTHOR  "F4HWN"
#define NAME    "M5DialSun"

#include <Preferences.h>
#include <HTTPClient.h>
#include <M5Dial.h>
#include <time.h>
#include <ESP32Time.h>

// Config
struct Config {
  char wifiSSID[64]      = "YOUR WIFI SSID";                                // Wifi SSID
  char wifiPassword[64]  = "YOUR WIFI PASSWORD";                            // Wifi Password
  char timeServer[128]   = "pool.ntp.org";                                  // NTP Server
  char timeTimeZone[128] = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";  // Geolocation timezone
};

Config myConfig;

// Sprite
LGFX_Sprite timeSprite(&M5Dial.Display);
LGFX_Sprite legendSprite(&M5Dial.Display);
LGFX_Sprite photoSprite(&M5Dial.Display);

// RTC
ESP32Time rtc;
boolean viewClock = false;
String last;

// Data
String endpointNasa = "http://rrf.globalis-dev.com:8080/html/hamqsl/";
String photo[]      = {"94",   "131",  "171",       "193",       "211", "304",     "335",     "1600",
                       "1700", "4500", "hmi_igram", "hmi_mgram", "xrt", "solisHe", "solisCh", "K_line"};
String legend[]     = {"Fe XVIII 94 A",     "Fe XX 131 A",      "Fe IX/X 171 A",   "Fe XII 193 A",
                       "Fe XIV 211 A",      "He II 304 A",      "Fe XVI 335 A",    "continuum + C IV 1600 A",
                       "continuum 1700 A",  "continuum 4500 A", "HMI magnetogram", "HMI intensitygram",
                       "Hinode XRT BeThin", "He I 10830 A",     "Ca II 8542 A",    "RISE/PSPT Ca II K"};
int8_t current      = 0;
size_t limit        = sizeof(photo) / sizeof(photo[0]);
boolean change      = false;

// Others variables
boolean wifiConnected;
long newPosition;
long oldPosition = -999;
