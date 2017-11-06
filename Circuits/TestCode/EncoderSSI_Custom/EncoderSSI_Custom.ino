// Definitions for the AEAT-6010
int  NCS = 4;
int SSI_CLK = 5;
int  DataIN = 6;

int pinHIGH = 3;
int pinLOW = 2;
int valHIGH, valLOW;
 
// Definitions for variables
unsigned int reading;
 
// program starts here
// **************************
 
void setup() {                
 
  Serial.begin(9600);
 
  // initialize the digital pin as an output.
  pinMode(NCS, OUTPUT);   // Chip select
  pinMode(SSI_CLK, OUTPUT);   // Serial clock
  pinMode(DataIN, INPUT);   // Serial data IN/OUT

  pinMode(pinHIGH, INPUT);
  pinMode(pinLOW, INPUT);
 
  digitalWrite(SSI_CLK, HIGH);  
}
 
//***********************************************************************
// Main program loop
//***********************************************************************
void loop() {
  valHIGH = digitalRead(pinHIGH);
  valLOW = digitalRead(pinLOW);
  Serial.print(valHIGH);
  Serial.print(valLOW);
  Serial.println("");
   
  ReadSSI();
  Serial.println(reading, DEC);
  Serial.println("");
  
  delay(100);
}
 
//***********************************************************************
// Main Loop ends here
// Start of subroutines
//***********************************************************************
 
void ReadSSI(void)
{
  int i;
  char Res = 10;
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
   
    if (i == 1) 
    {
      digitalWrite(SSI_CLK, HIGH);
      if (digitalRead(DataIN))
      {
        reading |= mask; 
      }
    }
  }
   
  digitalWrite(NCS, HIGH);
}
