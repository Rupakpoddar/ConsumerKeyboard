/*
  ConsumerKeyboard.h
  Extends the Arduino Keyboard library with consumer control functionality
*/

#ifndef CONSUMER_KEYBOARD_h
#define CONSUMER_KEYBOARD_h

#include "Keyboard.h"

#if defined(_USING_HID)

// Consumer Control Keys
// Power Control
#define CONSUMER_POWER                         0x0030
#define CONSUMER_RESET                         0x0031
#define CONSUMER_SLEEP                         0x0032

// Screen Brightness
#define CONSUMER_BRIGHTNESS_UP                 0x006F
#define CONSUMER_BRIGHTNESS_DOWN               0x0070

// Media Control
#define CONSUMER_PLAY_PAUSE                    0x00CD
#define CONSUMER_SCAN_NEXT                     0x00B5
#define CONSUMER_SCAN_PREVIOUS                 0x00B6
#define CONSUMER_STOP                          0x00B7
#define CONSUMER_VOLUME                        0x00E0
#define CONSUMER_MUTE                          0x00E2
#define CONSUMER_VOLUME_UP                     0x00E9
#define CONSUMER_VOLUME_DOWN                   0x00EA

// Application Control
#define CONSUMER_EMAIL                         0x018A
#define CONSUMER_CALCULATOR                    0x0192
#define CONSUMER_BROWSER                       0x0194

// Browser Control
#define CONSUMER_SEARCH                        0x0221
#define CONSUMER_HOME                          0x0223
#define CONSUMER_BACK                          0x0224
#define CONSUMER_FORWARD                       0x0225
#define CONSUMER_REFRESH                       0x0227
#define CONSUMER_BOOKMARKS                     0x022A

class ConsumerKeyboard_ : public Keyboard_
{
private:
    void sendConsumerReport(uint16_t k);

public:
    ConsumerKeyboard_(void);
    size_t consumerPress(uint16_t k);
    size_t consumerRelease();
    // Override releaseAll to also release consumer keys
    void releaseAll(void);
};

extern ConsumerKeyboard_ ConsumerKeyboard;

#endif
#endif