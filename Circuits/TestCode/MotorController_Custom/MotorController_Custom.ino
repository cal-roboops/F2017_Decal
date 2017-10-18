
int dirPin = 1;
int potPin = 1;
int maxDuty = 1023;
int dutyCycle = 0;


void setup() {
  pinMode(dirPin, OUTPUT);
}

void loop() {

  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  dutyCycle = analogRead(potPin);
  analogWrite(dirPin, dutyCycle / 4)

  // Wait short period
  delay(100);
}

