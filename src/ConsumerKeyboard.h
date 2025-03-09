/*
  ConsumerKeyboard.h
  Extends the Arduino Keyboard library with consumer control functionality
*/

#ifndef CONSUMER_KEYBOARD_H
#define CONSUMER_KEYBOARD_H

#include "HID.h"

#if defined(_USING_HID)

// Generic Control
#define HID_USAGE_CONSUMER_CONTROL             0x0001

// Power Control
#define KEY_POWER                              0x0030
#define KEY_RESET                              0x0031
#define KEY_SLEEP                              0x0032

// Screen Brightness
#define KEY_BRIGHTNESS_INCREMENT               0x006F
#define KEY_BRIGHTNESS_DECREMENT               0x0070

// Media Control
#define KEY_PLAY_PAUSE                         0x00CD
#define KEY_SCAN_NEXT                          0x00B5
#define KEY_SCAN_PREVIOUS                      0x00B6
#define KEY_STOP                               0x00B7
#define KEY_VOLUME                             0x00E0
#define KEY_MUTE                               0x00E2
#define KEY_BASS                               0x00E3
#define KEY_TREBLE                             0x00E4
#define KEY_BASS_BOOST                         0x00E5
#define KEY_VOLUME_INCREMENT                   0x00E9
#define KEY_VOLUME_DECREMENT                   0x00EA
#define KEY_BASS_INCREMENT                     0x0152
#define KEY_BASS_DECREMENT                     0x0153
#define KEY_TREBLE_INCREMENT                   0x0154
#define KEY_TREBLE_DECREMENT                   0x0155

// Application Launcher
#define KEY_AL_CONSUMER_CONTROL_CONFIGURATION  0x0183
#define KEY_AL_EMAIL_READER                    0x018A
#define KEY_AL_CALCULATOR                      0x0192
#define KEY_AL_LOCAL_BROWSER                   0x0194

// Browser/Explorer Specific
#define KEY_AC_SEARCH                          0x0221
#define KEY_AC_HOME                            0x0223
#define KEY_AC_BACK                            0x0224
#define KEY_AC_FORWARD                         0x0225
#define KEY_AC_STOP                            0x0226
#define KEY_AC_REFRESH                         0x0227
#define KEY_AC_BOOKMARKS                       0x022A

// Mouse Horizontal scroll
#define KEY_AC_PAN                             0x0238


class ConsumerKeyboard_
{
private:
    void sendReport(uint16_t k);

public:
    ConsumerKeyboard_(void);
    void begin(void);
    size_t press(uint16_t k);
    size_t release(void);
};

extern ConsumerKeyboard_ ConsumerKeyboard;

#endif
#endif
