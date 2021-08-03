// PROTOBot Code

#include <Servo.h>                        // Load "Servo" library
Servo servoLeft;                          // Left drive servo
Servo servoRight;                         // Right drive servo
const int BumpLeft = 4;               // Left bumper Pin 4
const int BumpRight = 5;             // Right bumper Pin 5
int BumpStateLeft = 0;                // Set Pin value
int BumpStateRight = 0;              // Set Pin value
void setup() {
  Serial.begin(9600);                    // Setup serial monitor for debug
  servoLeft.attach(2);                   // Set left servo to pin 2
  servoRight.attach(3);                 // Set right servo to pin 3
  pinMode(BumpLeft, INPUT_PULLUP);             // Set BumperLeft to input with pullup resistor
  pinMode(BumpRight, INPUT_PULLUP);            // Set BumperRight to input with pullup resistor
}

void loop() {                                 // Main programming loop

  BumpStateLeft = digitalRead(BumpLeft);        // Read left bumper
  Serial.println (BumpStateLeft, DEC);               // Print state of bumber
  if (BumpStateLeft == 0) {                                 // Check to see if left bumper has been pressed

    halt();                                                      // Stop
    reverse();                                                // Go backward
    halt();                                                      // Stop
    clockwise();                                            // Turn clockwise
    halt();                                                      // Stop
  }

  BumpStateRight = digitalRead(BumpRight);   // Read right bumper
  Serial.println (BumpStateRight, DEC);            // Print state of bumper
  if (BumpStateRight == 0) {                              // Check to see if right bumper has been pressed

    halt();                                                      // Stop
    reverse();                                               // Go backward
    halt();                                                     // Stop
    counterclockwise();                               // Turn counterclockwise
    halt();                                                    // Stop
  }

  forward();                                                      // Go forward
}

void forward() {                                               // Forward subroutine
  servoLeft.write(180);
  servoRight.write(0);
  delay(2);
}

void reverse(){                                               // Reverse subroutine
  servoLeft.write(0);
  servoRight.write(180);
  delay(400);
}

void clockwise() {                                         // Clockwise subroutine
  servoLeft.write(180);
  servoRight.write(180);
  delay(400);
}

void counterclockwise() {                            // Counterclockwise subroutine
  servoLeft.write(0);
  servoRight.write(0);
  delay(600);
}

void left() {                                                   // Left wheel forward subroutine
  servoLeft.write(90);
  servoRight.write(0);
  delay (2);
}

void right() {                                                 // Right wheel forward subroutine
  servoLeft.write(180);
  servoRight.write(90);
  delay (2);
}

void halt() {                                                  // Stop subroutine
  servoLeft.write(90);
  servoRight.write(90);
  delay (100);
}
