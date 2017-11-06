int dirPinIN = 2;
int dirPinOUT = 3;
int PWMPinOUT = 6;
int potPinIN = A1;

int dirOLD = 0;
int dirNEW = 0;
int dutyCycle = 0;

void setup()
{
  // Setup the pins
  pinMode(dirPinIN, INPUT);
  pinMode(dirPinOUT, OUTPUT);
  pinMode(PWMPinOUT, OUTPUT);

  // Write zero PWM
  analogWrite(PWMPinOUT, 255);
  delay(100);

  // Set direction
  dirNEW = digitalRead(dirPinIN);
  digitalWrite(dirPinOUT, dirNEW);
  dirOLD = dirNEW;

  Serial.begin(9600);
}

void loop()
{
  // Check if direction changed
  dirNEW = digitalRead(dirPinIN);
  if (dirNEW != dirOLD)
  {
    Serial.println("Switching Direction!");

    // Stop PWM to prevent circuit blowout
    analogWrite(PWMPinOUT, 255);
    delay(100);

    // Change direction
    digitalWrite(dirPinOUT, dirNEW);
    dirOLD = dirNEW;
  }

  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  // Values dependent on 5V, only had 4V signal so adjsuted
  dutyCycle = min(255, analogRead(potPinIN) / 2);
  analogWrite(PWMPinOUT, dutyCycle);

  // Output set speed
  Serial.print("Speed: ");
  Serial.println(dutyCycle);

  // Wait short period
  delay(100);
}

