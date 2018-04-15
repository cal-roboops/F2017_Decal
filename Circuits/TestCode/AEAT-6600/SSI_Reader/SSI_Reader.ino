// Definitions for the AEAT-6010
int  NCS = 4;
int SSI_CLK = 5;
int  DataIN = 6;

int magHIGH = 11;
int magLOW = 12;
int valHIGH, valLOW;
 
// Definitions for variables
unsigned long reading;
uint8_t delay_us = 1;
int pollWaitMS = 100;

void setup()
{
  Serial.begin(9600);
 
  // initialize the digital pin as an output.
  pinMode(NCS, OUTPUT);   // Chip select
  pinMode(SSI_CLK, OUTPUT);   // Serial clock
  pinMode(DataIN, INPUT);   // Serial data IN/OUT

  pinMode(magHIGH, INPUT);
  pinMode(magLOW, INPUT);

  digitalWrite(10, LOW);
 
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
  uint8_t i;
  uint8_t Res = 10;
  unsigned long mask;
  uint8_t rd;
  
  reading = 0;
  mask = 0x0200;
  
  digitalWrite(NCS, LOW);
  delayMicroseconds(delay_us);
  
  digitalWrite(SSI_CLK, LOW);
  delayMicroseconds(delay_us);

//  digitalWrite(SSI_CLK, HIGH);
//  delayMicroseconds(delay_us);
 
  for (i = 0; i < Res; i++)
  {

    digitalWrite(SSI_CLK, HIGH);
    rd = digitalRead(DataIN);
//    delayMicroseconds(delay_us);
    
    digitalWrite(SSI_CLK, LOW);
    reading = (reading << 1) | rd;
//    delayMicroseconds(delay_us);
  }
  
  digitalWrite(SSI_CLK, HIGH);
  rd = digitalRead(DataIN);
//  delayMicroseconds(delay_us);
  
  digitalWrite(SSI_CLK, LOW);
  reading = (reading << 1) | rd;
//  delayMicroseconds(delay_us);

  digitalWrite(NCS, HIGH);
  digitalWrite(SSI_CLK, HIGH);
  delayMicroseconds(delay_us);
}
