
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


}


long previousMillis = millis();
long currentMillis = millis();

boolean beingTouched = false;
int currentServoIndex = 0;

int positionToWriteToHigh = 90;
int positionToWriteToLow = 90;
int positionStagger = 8;
long currentMillisFullLoop = millis();
long previousMillisFullLoop = millis();

long resetCurrentMillis = millis();
long resetPreviousMillis = millis();


boolean up = true;
boolean animationTriggered = false;
int sensorPin = A18;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void loop() {
  currentMillis = millis();
  currentMillisFullLoop = millis();
  resetCurrentMillis = millis();

  if ((resetCurrentMillis - resetPreviousMillis > 8000) && animationTriggered) {

    animationTriggered = false;
    Serial.println("Resetting loop");

  }

  sensorValue = analogRead(sensorPin);
//  Serial.println(sensorValue);
  // turn the ledPin on
  if (sensorValue > 400 && !animationTriggered) {
    Serial.print("S Value : ");
    Serial.println(sensorValue);
    animationTriggered = true;
    resetCurrentMillis = millis();
    resetPreviousMillis = millis();
    Serial.println("SOUND DETECTED");
  }


//   Once all Servos have completed all movement then take a break
  if ((currentMillisFullLoop - previousMillisFullLoop > 1000) && animationTriggered) {
    if (currentMillis - previousMillis > 100) {
      //    Serial.print("Moving pin : ");
      //    Serial.println(pins[currentServoIndex]);
      //
      //    Serial.print("Moving x many degrees : ");
      //    Serial.println(positionToWriteToHigh);
      if (currentServoIndex >= NUM_SERVOS) {
        positionToWriteToHigh += positionStagger;
        positionToWriteToLow -= positionStagger;
        currentServoIndex = 0;

      }

      if (positionToWriteToHigh > 180) {
        positionToWriteToHigh = 0;


      }

      if (positionToWriteToLow < 0) {
        positionToWriteToLow = 180;
        previousMillisFullLoop = currentMillisFullLoop;

      }

      if (up) {

        moveServoRight(currentServoIndex, positionToWriteToHigh);
        up = false;
      } else {
        moveServoRight(currentServoIndex, positionToWriteToLow);
        up = true;


      }


      currentServoIndex++;
      previousMillis = currentMillis;



    }

  }
}

void moveServoRight(int pin, int servoPosition) {

  servos[pin].write(servoPosition);

}


int maxDegreess = 180;
int minDegrees = 0;

void moveServo(int pin) {

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servos[pin].write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }

  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servos[pin].write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }

}
boolean isBeingTouched() {

  int currentTouchReading = touchRead(23);
  return (currentTouchReading > 2000);



}

