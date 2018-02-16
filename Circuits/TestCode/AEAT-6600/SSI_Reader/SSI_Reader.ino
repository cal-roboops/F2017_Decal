// Definitions for the AEAT-6010
int  NCS = 4;
int SSI_CLK = 5;
int  DataIN = 6;

int magHIGH = 3;
int magLOW = 2;
int valHIGH, valLOW;

int pollWaitMS = 100;
 
// Definitions for variables
unsigned long reading;

void setup()
{
  Serial.begin(9600);
 
  // initialize the digital pin as an output.
  pinMode(NCS, OUTPUT);   // Chip select
  pinMode(SSI_CLK, OUTPUT);   // Serial clock
  pinMode(DataIN, INPUT);   // Serial data IN/OUT

  pinMode(magHIGH, INPUT);
  pinMode(magLOW, INPUT);
 
  digitalWrite(SSI_CLK, HIGH);
}

void loop()
{
  valHIGH = digitalRead(magHIGH);
  valLOW = digitalRead(magLOW);
  Serial.print(valHIGH);
  Serial.print(valLOW);
  Serial.println("");
  
  ReadSSI();
  Serial.println(reading, DEC);
  Serial.println("");
  
  delay(pollWaitMS);
}

void ReadSSI(void)
{
  int i;
  int Res = 10;
  unsigned long mask;
  
  reading = 0;
  mask = 0x0200;
  
  digitalWrite(NCS, LOW);
  delayMicroseconds(1);
  
  digitalWrite(SSI_CLK, LOW);
  delayMicroseconds(1);
 
  for (i = (Res-1); i > 0; i--)
  {
    digitalWrite(SSI_CLK, HIGH);
    delayMicroseconds(1);
    
    if (digitalRead(DataIN))
    {
      reading |= mask;
    }
    
    digitalWrite(SSI_CLK, LOW);
    delayMicroseconds(1);
    
    mask = mask >> 1;
  }
  
  digitalWrite(SSI_CLK, HIGH);
  if (digitalRead(DataIN))
  {
    reading |= mask; 
  }
  
  digitalWrite(NCS, HIGH);
}
