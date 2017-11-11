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
  //Serial.println("");

  // Print A & B
  Serial.print(incA);
  Serial.print(" ");
  Serial.print(incB);
  Serial.println("");

  ReadSSI();
  Serial.println(reading, DEC);
  Serial.println("");
  
  Serial.println("");

  // Wait short period
  delay(50);
}

void ReadSSI(void)
{
  int i;
  char Res = 16;
  unsigned int mask;
  
  reading = 0;
  mask = 0x0200;
  digitalWrite(NCS, LOW);
  delayMicroseconds(1);
  digitalWrite(SSI_CLK, LOW);
 
  for (i = (Res-1); i > 0; i--)
  {
    digitalWrite(SSI_CLK, HIGH);
    delayMicroseconds(1);
    
    if (digitalRead(DataIN))
    {
      reading |= mask;
    }
    
    digitalWrite(SSI_CLK, LOW);
    mask = mask >> 1;
  }
  
  digitalWrite(SSI_CLK, HIGH);
  if (digitalRead(DataIN))
  {
    reading |= mask; 
  }
  
  digitalWrite(NCS, HIGH);
}

