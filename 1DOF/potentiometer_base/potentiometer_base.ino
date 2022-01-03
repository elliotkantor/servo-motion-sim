/* Potentiometer to servo
 * VCC - 5V
 * GND - GND
 * Servo control - 2 
 * Potentiometer output - A3 (it's important that this is analog)
 */

#include <Servo.h>

Servo baseServo;  // define 1DOF servo, in this case around the z axis
int baseServoPos = 0;  // initial position (deg)
int baseServoPin = 2;  // pin to connect servo input

int potPin = 3;  // potentiometer output 


void setup() {
  baseServo.attach(baseServoPin);
}

void loop() {
  baseServoPos = analogRead(potPin);  // read value of potentiometer
  baseServoPos = map(baseServoPos, 0, 1023, 0, 180);  // map to 0 - 180 degrees from original 0 - 1023 range
  baseServo.write(baseServoPos);  // apply transformation
}
