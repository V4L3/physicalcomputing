//Button
int inputButton = 12;
int buttonState;
//LED
int whiteLED = 9;

void setup() {
  //Button
  pinMode(inputButton, INPUT);
  Serial.begin(9600);
  //LED
  pinMode(whiteLED, OUTPUT);
}

void loop() {
  //Button
  buttonState = digitalRead(inputButton);
  Serial.println(buttonState);
  delay(1);//Stability reasons
  //LED
  if (buttonState >= 1) {
    digitalWrite(whiteLED, HIGH);
  } else {
    digitalWrite(whiteLED, LOW);
  }
}

