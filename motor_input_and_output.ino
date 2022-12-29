
// Motor Output Code Snippet

#include <Servo.h>              // Load "Servo" library
Servo servomotor;               // Define servo name
const int bump = 4;             // Bumper Pin 4
int bumpstate = 0;              // Set Bump State value

void setup() {
  servomotor.attach(2);          // Set servomotor to pin 2
  Serial.begin(9600);            // Setup serial monitor for monitoring switch
  pinMode (bump, INPUT_PULLUP);  // Set bump to input with pullup resistor
}

void loop() {
  bumpstate = digitalRead(bump);    // Read bumper state
  Serial.println (bumpstate, DEC);  // Print bumperstate in Serial Monitor
  if (bumpstate == 0) {
    stop();
  } else {
    servomotor.write(180);
  }
}

void stop() {
  servomotor.write(90);
}
