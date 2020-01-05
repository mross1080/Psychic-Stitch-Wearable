/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo
Servo myservo5;  // create servo object to control a servo

int pins [] = {22, 21, 20, 19, 16};
// twelve servo objects can be created on most boards
Servo servos[] = {myservo, myservo2, myservo3, myservo4, myservo5};
int pos = 0;    // variable to store the servo position
int lowestPinNum = 19;
int NUM_SERVOS = 5;
void setup() {
  Serial.begin(9600);

  for (int x = 0; x < NUM_SERVOS; x++) {
    servos[x].attach(pins[x]);
  }

  //  myservo.attach(22);  // attaches the servo on pin 9 to the servo object
  //  myservo2.attach(21);  // attaches the servo on pin 9 to the servo object
  //  myservo3.attach(20);  // attaches the servo on pin 9 to the servo object
  //  myservo4.attach(19);
  //  myservo5.attach(16);

}

boolean beingTouched = false;

void loop() {
  for (int x = 0; x < NUM_SERVOS; x++) {
    moveServo(x);
  }

  //  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //    // in steps of 1 degree
  //    myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //
  //  }

  //  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //    myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //  }
  //
  //  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //    // in steps of 1 degree
  //    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //
  //
  //  }

  //  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //  }
  //
  //  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //    // in steps of 1 degree
  //    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //
  //
  //  }
  //
  //  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //  }
  //  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //    // in steps of 1 degree
  //    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //
  //
  //  }
  //
  //  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //  }
  //
  //  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //    // in steps of 1 degree
  //    myservo5.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //
  //
  //  }
  //
  //  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //    myservo5.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(5);                       // waits 15ms for the servo to reach the position
  //  }


}

void moveServo(int pin) {

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servos[pin].write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  //  }
  //  Serial.println(touchRead(23));
  //  if (isBeingTouched()) {
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servos[pin].write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }

}
boolean isBeingTouched() {

  int currentTouchReading = touchRead(23);
  return (currentTouchReading > 2000);



}

