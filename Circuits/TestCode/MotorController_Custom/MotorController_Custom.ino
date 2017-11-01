
int dirPinIN = 2;
int dirPinOUT = 3;
int PWMPinOUT = 6;
int potPinIN = A1;

int dirOLD = 0;
int dirNEW = 0;
int dutyCycle = 0;

void setup() {
  pinMode(dirPinIN, INPUT);
  pinMode(dirPinOUT, OUTPUT);
  pinMode(PWMPinOUT, OUTPUT);

  analogWrite(PWMPinOUT, 0);
  delay(100);
  
  dirNEW = digitalRead(dirPinIN);
  digitalWrite(dirPinOUT, dirNEW);
  dirOLD = dirNEW;

  Serial.begin(9600);
}

void loop() {
  dirNEW = digitalRead(dirPinIN);
  if (dirNEW != dirOLD)
  {
    Serial.println("Switching Direction!");

    analogWrite(PWMPinOUT, 0);
    delay(100);

    digitalWrite(dirPinOUT, dirNEW);
    dirOLD = dirNEW;
  }

  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  dutyCycle = min(255, analogRead(potPinIN) / 2);
  analogWrite(PWMPinOUT, dutyCycle);
  
  Serial.print("Speed: ");
  Serial.println(dutyCycle);

  // Wait short period
  delay(100);
}

