#include <Servo.h>
Servo myServo;
int leftPRes; //east photoresistor
int rightPRes; //west photoresistor
int difference; //difference between values
int servoPos; //represents servo position
int servoMiddle=110; //servo position that makes solar panel flat

void setup() {
  Serial.begin(9600);
  myServo.attach(9); //attaches servo to pin 9

  for (int pos = 0; pos <= servoMiddle; pos += 1) { //sets servo position to middle
    myServo.write(pos);
    delay(1);
  }

void loop() {
  leftPRes = analogRead(A0);
  rightPRes = analogRead(A1);
  difference= leftPRes-rightPRes;

  Serial.println(leftPRes); //next 4 lines for debugging
  Serial.println(rightPRes);
  Serial.println(difference);
  Serial.println("next iteration");

  if (difference>0) { //turns solar panels towards light by seeing the difference in photoresistors
    if (servoPos<175); {
      servoPos+= 5;
      myServo.write(servoPos);
      Serial.println(servoPos);
    }
    delay(1000);
  }

  if (difference<0) {
    if (servoPos>5) {
      servoPos-= 5;
      myServo.write(servoPos);
      Serial.println(servoPos);
    }
    delay(1000);
  }
  
  }
