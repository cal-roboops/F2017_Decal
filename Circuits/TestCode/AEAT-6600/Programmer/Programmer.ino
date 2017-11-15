// Definitions for the AEAT-6010
int NCS = 4;
int SSI_CLK = 5;
int DataOUT = 6;
int ProgPin = 7;
int ProgStatus = 2;
int ProgSuccess = 3;

int progError, progComplete;

// Decision pins
int writePIN = 8;
int resetPIN = 9;
int writeVAL, resetVAL;

// Global storage variables
unsigned long progVal;
unsigned long Mode_Lo, Mode_Hi;
unsigned long Zero_Lo, Zero_Hi;
unsigned int progBits, RW;
int i;
bool notProg;
 
void setup()
{  
  Serial.begin(9600);
  Serial.print("Setting up...");
  
  // Initialize the pins
  pinMode(NCS, OUTPUT);   // Chip select
  pinMode(SSI_CLK, OUTPUT);   // Serial clock
  pinMode(DataOUT, OUTPUT);   // Serial data IN/OUT
  pinMode(ProgPin, OUTPUT); // Programming enable
  
  pinMode(ProgStatus, INPUT); // Programming Status
  pinMode(ProgSuccess, INPUT); // Programming Success/Failed
  pinMode(writePIN, INPUT); // Start Programming Button
  pinMode(resetPIN, INPUT); // Reset Programmibng Button

  digitalWrite(ProgPin, HIGH);
  digitalWrite(SSI_CLK, HIGH);

  // Program settings
  RW = 1; // 0: Read, 1:Write
  Mode_Lo = 0b00011110; // Set Inc Resolutions and
  Mode_Hi = 0b01101011; // Set Mode & Abs Resolution
  Zero_Lo = 0b00000000; // Programmable Zero Position
  Zero_Hi = 0b00000000; // Programmable Zero Position
  progVal = (Zero_Hi << 24) | (Zero_Lo << 16) | (Mode_Hi << 8) | (Mode_Lo);
  progBits = 32;

  notProg = true;
  Serial.print("Ready to Program: 0x");
  Serial.println(progVal, HEX);
}

void loop()
{
  writeVAL = digitalRead(writePIN);
  resetVAL = digitalRead(resetPIN);

  if (writeVAL & notProg)
  {
    Serial.print("Programming: 0x");
    Serial.println(progVal, HEX);
    WriteSSI();
    delay(1);
    notProg = false;
  } else if (resetVAL & !notProg)
  {
    notProg = true;
    Serial.print("Ready to Program: 0x");
    Serial.println(progVal, HEX);
  }

  progError = digitalRead(ProgStatus);
  progComplete = digitalRead(ProgSuccess);
  Serial.print(progError);
  Serial.print(progComplete);
  Serial.println("");
  
  delay(1000);
}

void WriteSSI(void)
{
  unsigned long mask;
  unsigned long evenPar;
  unsigned long progVal;
  
  // Setup variables
  progVal = 0x6B1E;
  evenPar = 1;
  mask = 0x80000000;

  // Setup clocking
  digitalWrite(NCS, LOW);
  delayMicroseconds(1);
  digitalWrite(SSI_CLK, LOW);
  delayMicroseconds(1);

  // Write the read/write signal
  digitalWrite(SSI_CLK, HIGH);
  digitalWrite(DataOUT, 1);
  delayMicroseconds(1);
  digitalWrite(SSI_CLK, LOW);

  // Write the 32 bits of data
  for (i = progBits; 0 < i; i--)
  {
    digitalWrite(SSI_CLK, HIGH);    
    digitalWrite(DataOUT, mask & progVal);
    delayMicroseconds(1);
    
    digitalWrite(SSI_CLK, LOW);
    mask = mask >> 1;
  }

  // Write Parity Bit
  digitalWrite(SSI_CLK, HIGH);
  digitalWrite(DataOUT, evenPar);
  delayMicroseconds(1);
  digitalWrite(SSI_CLK, LOW);

  // End communication
  digitalWrite(NCS, HIGH);
}
