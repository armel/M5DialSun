# M5DialSun
![dial](https://img.shields.io/badge/M5Stack-DIAL-orange)

**Many thanks to them and all my [donors](#donations)🙏🏻** 

This tiny project shows currents photos of the sun in different wavelengths.

# Compilation

First, edit `M5DialSun.h` file and change `struct Config` with your settings:

```
struct Config {
  char wifiSSID[64]      = "YOUR WIFI SSID";                                // Wifi SSID
  char wifiPassword[64]  = "YOUR WIFI PASSWORD";                            // Wifi Password
  char timeServer[128]   = "pool.ntp.org";                                  // NTP Server
  char timeTimeZone[128] = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";  // Geolocation timezone
};
```

> Note: the default timeTimeZone is France (Europe/Paris). If you need to adapt the timezone, consult this more detailed [list](https://github.com/blindsidenetworks/bigbluebutton-1/blob/master/bbb-voice-conference/config/freeswitch/conf/autoload_configs/timezones.conf.xml). Contact me if you need help or if you live in an exotic region... Nevertheless, here are a few examples of values:

| Country           | Timezone             | 
| -------------- | -------------------- |
| Europe/Paris | CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00 |
| Europe/Berlin | CET-1CEST,M3.5.0,M10.5.0/3 |
| Europe/Brussels | CET-1CEST,M3.5.0,M10.5.0/3 |
| Europe/Bucharest | EET-2EEST,M3.5.0/3,M10.5.0/4 |
| Europe/London | GMT0BST,M3.5.0/1,M10.5.0 |
| Europe/Sofia | EET-2EEST,M3.5.0/3,M10.5.0/4 |
| America/Los_Angeles | PST8PDT,M3.2.0,M11.1.0 |
| America/New_York | EST5EDT,M3.2.0,M11.1.0 |
| America/Martinique | AST4 |
| America/Montreal | EST5EDT,M3.2.0,M11.1.0 |
| America/Guadeloupe | AST4 |
| Australia/Brisbane | EST-10 |
| Asia/Hong_Kong | HKT-8 |
| Asia/Tokyo | JST-9 |
| Pacific/Noumea | NCT-11 |

You can compile the source code.

# Flash your M5Dial

Be aware ! If you want to enter download mode, press and hold the G0 button on StampS3 before turning it on, then release it after powering it on.

# Usage

Use M5Dial rotary encoder to change current solar photo in different wavelengths.

Use bottom button to show or hide clock and legend.

# Credits
 
Many thanks to...

| Project             | Author                                                |  Link                                           |
|:------------------- | :---------------------------------------------------- | :---------------------------------------------- |
| M5Unified           | [Lovyan03](https://twitter.com/lovyan03)              | https://github.com/m5stack/M5Unified            |
| Current solar images  | Nasa                                               | https://umbra.nascom.nasa.gov/images/             |

# Donations

Special thanks to Rolf Schroeder DL8BAG, Brian Garber WB8AM, Matt B-Wilkinson M6VWM, Robert Agnew KD0TVP, Meinhard Frank Günther DL0CN, Johan Hansson SM0TSC, Tadeusz Pater VA7CPM, Frederic Ulmer F4ESO, Joshua Murray M0JMO, Mark Hammond N8MH, Angel Mateu Muzzio EA4GIG (2 times 🍷🍷), Hiroshi Sasaki JL7KGW, Robert John Williams VK3IE, Mark Bumstead M0IAX, Félix Symann F1VEO, Patrick Ruhl DG2YRP, Michael Beck DH5DAX, Philippe Nicolas F4IQP, Timothy Nustad KD9KHZ, Martin Blanz DL9SAD, Edmund Thompson AE4TQ, Gregory Kiyoi KN6RUQ, Patrick Samson F6GWE, George Kokolakis SV3QUP, Ambrose "Bo" Barry W4GHV, Roger Bouche F1HCN, Christopher Platt, Pascal Paquet F4ICR, Gregory Kiyoi, Ning Yang BH7JAG, Mitsuhiko Nagasawa JL1LYT, Mike Mann G4GOC, David Cappello, Matt Brinkhoff KB0RXC, Franklin Beider WD9GZ, Robrecht Laurens ON4ROB, Florian Wolters DF2ET, James Gatwood WA9JG, Christoph Gässler DL6SEZ, Roger Kenyon WB2YOJ, Jean-pierre Billat F1RXM (2 times 🍷🍷), John Sheppard G4WOD, Jean-Cyrille Vercollier F6IWW, Kenneth Goins Jr, Tim Cowell G6GEI, Andreas Macrides M0FXB, Bogdan Manolache W4MHI and Jacob Mol N8JCM for their donations. That’s so kind of them. Thanks so much 🙏🏻

If you find this project fun and useful then [buy me a glass of wine](https://www.paypal.me/F4HWN) 🍷 🤗 

By the way, you can follow me on [Twitter](https://twitter.com/F4HWN) and post pictures of your installation with your M5Stack. It always makes me happy ;) 
