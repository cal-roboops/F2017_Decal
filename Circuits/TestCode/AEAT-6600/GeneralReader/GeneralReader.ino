int pinLOW = 2;
int pinHIGH = 3;
int  NCS = 4;
int SSI_CLK = 5;
int DataIN = 6;
int progPin = 7;
int pinA = 10;
int pinB = 11;
int pinI = 12;
int vA, vB, vI, vHi, vLo;

unsigned int reading;

void setup()
{
  Serial.begin(115200);
  
  // Setup Pins
  pinMode(NCS, OUTPUT);
  pinMode(SSI_CLK, OUTPUT);
  pinMode(DataIN, INPUT);
  pinMode(pinHIGH, INPUT);
  pinMode(pinLOW, INPUT);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinI, INPUT);
  pinMode(progPin, OUTPUT);

  digitalWrite(progPin, LOW);
  digitalWrite(SSI_CLK, HIGH);
}

void loop()
{  
  // Read pins
  vA = digitalRead(pinA);
  vB = digitalRead(pinB);
  vI = digitalRead(pinI);
  vHi = digitalRead(pinHIGH);
  vLo = digitalRead(pinLOW);

  // Print Values
  // A B I H L
  Serial.print(vA);
  Serial.print(vB);
  Serial.print(vI);
  Serial.print(vHi);
  Serial.print(vLo);
  Serial.println("");

  // Read Absolute
  ReadSSI();
  Serial.println(reading, DEC);
  Serial.println("");

  // Wait short period
  delay(250);
}

void ReadSSI(void)
{
  int i;
  int res = 10;
  unsigned long mask;
  
  reading = 0;
  mask = 0x0200;
  
  digitalWrite(NCS, LOW);
  delayMicroseconds(1);
  digitalWrite(SSI_CLK, LOW);
 
  for (i = (res-1); i > 0; i--)
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

