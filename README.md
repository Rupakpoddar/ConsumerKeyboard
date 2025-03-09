# ConsumerKeyboard Arduino Library

The **ConsumerKeyboard** library extends the Arduino HID functionality, enabling your Arduino to emulate consumer control devices. This allows you to send commands such as play/pause, volume adjustments, and more to a connected computer.

## Features

- **Power Controls**: Power, Reset, Sleep
- **Screen Brightness**: Brightness Increment/Decrement
- **Media Controls**: Play/Pause, Next/Previous Track, Stop, Volume, Mute, Bass, Treble
- **Application Launchers**: Email Reader, Calculator, Browser
- **Browser/Explorer Navigation**: Search, Home, Back, Forward, Stop, Refresh, Bookmarks
- **Mouse Horizontal Scroll**: Pan

## Compatibility

This library is compatible with the following architectures:

- AVR
- SAMD
- SAM
- Renesas

Ensure your Arduino board supports HID functionality to utilize this library effectively.

## Key Definitions

The library provides a comprehensive set of key definitions for various consumer control functions:

| Function                                 | Key Definition                             | Hex Code |
|------------------------------------------|---------------------------------------------|----------|
| **Generic Control**                      | HID_USAGE_CONSUMER_CONTROL                 | 0x0001   |
| **Power Control**                        | KEY_POWER                                  | 0x0030   |
|                                          | KEY_RESET                                  | 0x0031   |
|                                          | KEY_SLEEP                                  | 0x0032   |
| **Screen Brightness**                    | KEY_BRIGHTNESS_INCREMENT                   | 0x006F   |
|                                          | KEY_BRIGHTNESS_DECREMENT                   | 0x0070   |
| **Media Control**                        | KEY_PLAY_PAUSE                             | 0x00CD   |
|                                          | KEY_SCAN_NEXT                              | 0x00B5   |
|                                          | KEY_SCAN_PREVIOUS                          | 0x00B6   |
|                                          | KEY_STOP                                   | 0x00B7   |
|                                          | KEY_VOLUME                                 | 0x00E0   |
|                                          | KEY_MUTE                                   | 0x00E2   |
|                                          | KEY_BASS                                   | 0x00E3   |
|                                          | KEY_TREBLE                                 | 0x00E4   |
|                                          | KEY_BASS_BOOST                             | 0x00E5   |
|                                          | KEY_VOLUME_INCREMENT                       | 0x00E9   |
|                                          | KEY_VOLUME_DECREMENT                       | 0x00EA   |
|                                          | KEY_BASS_INCREMENT                         | 0x0152   |
|                                          | KEY_BASS_DECREMENT                         | 0x0153   |
|                                          | KEY_TREBLE_INCREMENT                       | 0x0154   |
|                                          | KEY_TREBLE_DECREMENT                       | 0x0155   |
| **Application Launcher**                 | KEY_AL_CONSUMER_CONTROL_CONFIGURATION      | 0x0183   |
|                                          | KEY_AL_EMAIL_READER                        | 0x018A   |
|                                          | KEY_AL_CALCULATOR                          | 0x0192   |
|                                          | KEY_AL_LOCAL_BROWSER                       | 0x0194   |
| **Browser/Explorer Specific**            | KEY_AC_SEARCH                              | 0x0221   |
|                                          | KEY_AC_HOME                                | 0x0223   |
|                                          | KEY_AC_BACK                                | 0x0224   |
|                                          | KEY_AC_FORWARD                             | 0x0225   |
|                                          | KEY_AC_STOP                                | 0x0226   |
|                                          | KEY_AC_REFRESH                             | 0x0227   |
|                                          | KEY_AC_BOOKMARKS                           | 0x022A   |
| **Mouse Horizontal Scroll**              | KEY_AC_PAN                                 | 0x0238   |
