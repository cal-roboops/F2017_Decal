// Definitions for the AEAT-6010
int NCS = 4;
int SSI_CLK = 5;
int DataOUT = 6;
int ProgPin = 7;
int ProgStatus = 11;
int ProgSuccess = 12;

int progError, progComplete;

// Decision pins
int writePIN = 8;
int resetPIN = 9;
int writeVAL, resetVAL;

// Global storage variables
uint32_t progVal;
uint8_t progBits, evenPar, i;
uint32_t Mode_Lo, Mode_Hi;
uint32_t Zero_Lo, Zero_Hi;
unsigned int RW;
bool notProg;
int delay_us = 2; // US delay
int progWaitMS = 500;
 
void setup()
{  
  Serial.begin(9600);
  Serial.println("Setting up...");
  
  // Initialize the pins
  pinMode(NCS, OUTPUT);   // Chip select
  pinMode(SSI_CLK, OUTPUT);   // Serial clock
  pinMode(DataOUT, OUTPUT);   // Serial data IN/OUT
  pinMode(ProgPin, OUTPUT); // Programming enable
  
  pinMode(ProgStatus, INPUT); // Programming Status
  pinMode(ProgSuccess, INPUT); // Programming Success/Failed
  pinMode(writePIN, INPUT); // Start Programming Button
  pinMode(resetPIN, INPUT); // Reset Programmibng Button

  RESET_SSI();
  
  digitalWrite(ProgPin, HIGH);
  digitalWrite(SSI_CLK, HIGH);
}

void loop()
{
  writeVAL = digitalRead(writePIN);
  resetVAL = 0; //digitalRead(resetPIN);

  if (writeVAL & notProg)
  {
    Serial.println("Programming...");

    digitalWrite(10, HIGH);
    
    WriteSSI();
    notProg = false;

    digitalWrite(10, LOW);

  } else if (resetVAL & !notProg)
  {
    RESET_SSI ();
  }

  progError = digitalRead(ProgStatus);
  progComplete = digitalRead(ProgSuccess);
  Serial.print(progError);
  Serial.print(progComplete);
  Serial.println("");
  
  delay(progWaitMS);
}

uint32_t reverseOrder (uint32_t val)
{
  uint32_t val_rev = 0;
  uint32_t val_cp = val;

  for (i = 0; i < progBits; i++)
  {
    val_rev = (val_rev << 1) | (val_cp & 1);
    val_cp = val_cp >> 1;
  }

  return val_rev;
}

void WriteSSI(void)
{
  // Setup local vars
  uint32_t progVal_rev = reverseOrder (progVal);
  uint32_t v = progVal_rev & 0x1;
  
  // Setup NCS, clocking, & first bit
  digitalWrite(DataOUT, RW);
  digitalWrite(NCS, LOW);
  digitalWrite(SSI_CLK, LOW);
  delayMicroseconds(delay_us);

  // Write the read/write signal
  digitalWrite(SSI_CLK, HIGH);
  delayMicroseconds(delay_us);

  // Write the 32 bits of data
  for (i = 0; i < progBits; i++)
  {
    digitalWrite(SSI_CLK, LOW);
    digitalWrite(DataOUT, v);
//    delayMicroseconds(delay_us);

    digitalWrite(SSI_CLK, HIGH);
    progVal_rev = progVal_rev >> 1;
    v = progVal_rev & 0x1;
//    delayMicroseconds(delay_us);
  }

  // Write Parity Bit
  digitalWrite(SSI_CLK, LOW);
  digitalWrite(DataOUT, evenPar);
//  delayMicroseconds(delay_us);
  
  digitalWrite(SSI_CLK, HIGH);
  delayMicroseconds(delay_us);

  // End communication
  digitalWrite(NCS, HIGH);
  digitalWrite(DataOUT, LOW);
}

uint8_t computeParity (uint32_t val)
{
  uint8_t p = 0;
  uint32_t val_cp = val;
  for (i = 0; i < progBits; i++)
  {
    p = p ^ (val_cp & 0x1);
    val_cp = val_cp >> 1;
  }
  return !(p & 0x1);
}

void RESET_SSI ()
{
  // Reset key vars
  progBits = 32; // Number of bits in program
  notProg = true;
  
  // Reset program settings
  RW = 1; // 0: Read, 1:Write
  Mode_Lo = 0b00011110; // Set Inc Resolutions and
  Mode_Hi = 0b01101011; // Set Mode & Abs Resolution
  Zero_Lo = 0b00000000; // Programmable Zero Position
  Zero_Hi = 0b00000000; // Programmable Zero Position
  progVal = (Zero_Hi << 24) | (Zero_Lo << 16) | (Mode_Hi << 8) | (Mode_Lo);
  evenPar = computeParity (progVal); // Get parity

  // Output and reverse order
  Serial.print("Ready to Program: 0x");
  Serial.println(progVal, HEX);
}

