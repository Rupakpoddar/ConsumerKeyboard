/*
  Consumer Keyboard Emulator
  Created by: @truth129

  This example code is in the public domain.

  This library allows you to control volume, mute, and other
  consumer control keys on a keyboard on the renesas and other arm
  based microcontrollers using the inbuilt Keyboard. It also allows
  the user to send any key to the keyboard.
*/

#include "Keyboard.h"

void setup() {
  Serial.begin(115200);

  delay(2000);
  Serial.println("Consumer Keyboard Emulator");
  Serial.println("Type u, d, m to control volume.");
  // initialize control over the keyboard:
  ConsumerKeyboard.begin();
  delay(5000);
}

void loop() {
  // check for incoming serial data:
    if (Serial.available() > 0) {
      // read incoming serial data:
      char inChar = Serial.read();
      switch (inChar) {
        case 'u':
          Serial.println("volume up");
          send_key(KEY_VOLUME_INCREMENT);
          break;
        case 'd':
          Serial.println("volume down");
          send_key(KEY_VOLUME_DECREMENT);
          break;
        case 'm':
          Serial.println("mute");
          send_key(KEY_MUTE);
          break;
        default:
          ConsumerKeyboard.write(inChar);
          break;
      }
    }
    delay(10);
}


void write_key(uint16_t key) {
  ConsumerKeyboard.consumerPress(key);
  ConsumerKeyboard.consumerRelease();
}
