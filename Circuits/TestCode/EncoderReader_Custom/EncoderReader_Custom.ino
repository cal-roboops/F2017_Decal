int pin, val;
int PWM_IN = 6;
int incA, incB, prevA, prevB;

void setup()
{
  // Setup Quad and mag Pins
  for (pin = 1; pin < 6; pin++)
  {
    pinMode(pin, INPUT);
  }

  // Setup PWM Input pin
  pinMode(PWM_IN, INPUT);

  // Zero values
  incA = incB = 0;
  prevA = digitalRead(1);
  prevB = digitalRead(2);
  
  Serial.begin(9600);
}

void loop()
{
  // Loop through the pins reading
  for (pin = 1; pin < 6; pin++)
  {
    val = digitalRead(pin);

    if (pin == 1)
    {
      if (val != prevA)
      {
        incA += 1;
        prevA = val;
      }
    } else if (pin == 2)
    {
      if (val != prevB)
      {
        incB += 1;
        prevB = val;
      }
    }
    
    Serial.print(val);
  }

  // Read the PWM Pin
  //val = pulseIn(PWM_IN, HIGH, 20000);
  //Serial.print(val);

  // New line
  Serial.println("");

  // Print A & B
  Serial.print(incA);
  Serial.print(" ");
  Serial.print(incB);
  
  Serial.println("");
  Serial.println("");

  // Wait short period
  delay(50);
}

