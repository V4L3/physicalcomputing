//Import servo stuff
#include <Servo.h>

//Smoothing stuff
const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;

//Potentiometer
int sensorPin = A0;
int sensorValue;
int degree = 0;

//Servothings
Servo myServo1;
Servo myServo2;
int pos;
int pinServo1=11;
int pinServo2=9;

void setup() {
  //Servothings
  pos = 0;
  myServo1.attach(pinServo1);
  myServo2.attach(pinServo2);
    Serial.begin(9600);
  //init array for smoothing stuff
  for(int i = 0; i< numReadings; i++) {
    readings[i] =0;
  }
}

void loop() {
  //Smoothing stuff
  total = total -readings[readIndex];
  readings[readIndex] = analogRead(sensorPin);
  total = total + readings[readIndex];
  readIndex = readIndex +1;

  if(readIndex >= numReadings) {
    readIndex =0;
  }

  average = total / numReadings;

  //Potentiometer
  sensorValue = analogRead(sensorPin);
  Serial.println(average);
  //map(value, fromLow, fromHigh, toLow, toHigh
  degree = map(average, 0, 1023, 0, 180);
  //analogWrite(ledPIN, average);
  myServo1.write(degree);
  myServo2.write(degree);
  delay(1); //Stability reasons
}

