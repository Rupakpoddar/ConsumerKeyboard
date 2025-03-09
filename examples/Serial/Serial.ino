/*
  Consumer Keyboard Emulator
  --------------------------
  
  Functionality:
    Initializes both standard keyboard and consumer HID interfaces
    Listens for serial input (u=volume up, d=volume down, m=mute)
    Sends consumer control reports for media keys

  Usage:
    Open serial monitor at 9600 baud
    Send commands:
      u : Volume up
      d : Volume down
      m : Mute toggle
  
  Reprogramming Arduino Uno R4:
    Double-press the reset button to enter download mode
    (Built-in LED will fade in and out)
    Re-select the port and upload new code
*/

#include "Keyboard.h"
#include "ConsumerKeyboard.h"

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  delay(2000);

  Serial.println("Consumer Keyboard Emulator");
  Serial.println("Type u, d, m to control volume.");
}

void loop() {
  // Check for incoming serial data:
  if (Serial.available() > 0) {
    // Read incoming serial data:
    char inChar = Serial.read();
    switch (inChar) {
      case 'u':
        Serial.println("Volume Up");
        send_key(KEY_VOLUME_INCREMENT);
        break;
      case 'd':
        Serial.println("Volume Down");
        send_key(KEY_VOLUME_DECREMENT);
        break;
      case 'm':
        Serial.println("Mute");
        send_key(KEY_MUTE);
        break;
      default:
        Keyboard.write(inChar);
        break;
    }
  }
  delay(10);
}

void send_key(uint16_t key) {
  ConsumerKeyboard.press(key);
  ConsumerKeyboard.release();
}
