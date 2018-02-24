#include <SPI.h>
#include <printf.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>

// RF Variables
RF24 radio(8,10);
const uint64_t pipes[2] = { 0xABCDABCD71LL, 0x544d52687CLL };  // Address of PTX and PRX
int interrupt_time = 10; // In millisenconds (Do not overdo it with too short interrupt time)
byte Int_cnt = 0; // Interrupt counter
byte Int_TX_cnt = 5; // Setting up the number of interrupts count that trig the data tramission 
volatile boolean fired = false;

byte fhss_schema[]={11, 46, 32, 49, 60, 88, 77, 85, 94, 100, 115, 120, 104, 107, 90, 93, 86, 80, 64, 58, 41, 39, 3, 33, 30, 14, 5, 24};
byte ptr_fhss_schema = 0; // Pointer to the fhss_schema array

// Buffer Variables
const int len = 48;
char data[len];

// Reading Variables
int readLen;
char* str;

// Function prototypes
int readNext(char sChar);
void parseReceived();
void sendFile();
void setMode();
void modeTX();
void modeRX();
void modeTXRX();
void modeNONE();

// Arduino setup function
void setup()
{
  Serial.setTimeout(1000);
  Serial.begin(115200);

  printf_begin();
  radio.begin();
  radio.setPALevel(RF24_PA_LOW); // RF24_PA_MIN (-18dBm), RF24_PA_LOW (-12dBm), RF24_PA_HIGH (-6dBM), RF24_PA_MAX (0dBm)
  radio.setRetries(4,9);
  radio.setAutoAck(1);
  radio.enableAckPayload();
  radio.enableDynamicPayloads();
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(fhss_schema[ptr_fhss_schema]);
  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1,pipes[0]);

  radio.startListening();
  radio.printDetails();

  TCCR1A = 0;
  TCCR1B = 1<<WGM12 | 1<<CS11;
  TCNT1 = 0;         // reset counter
  OCR1A =  (interrupt_time*2000)-1;       // compare A register value 
  TIFR1 |= _BV (OCF1A);    // clear interrupt flag
  TIMSK1 = _BV (OCIE1A);   // interrupt on Compare A Match
}

// Arduino Loop function
void loop()
{
  // Wait for serial data to be available
  while (Serial.available() > 0)
  {
    // Read data until comma char
    if (readNext(',') != 0)
    {
      parseReceived();
  
      // Set buffer back to 0 after done parsing
      memset(data, 0, sizeof(data));
    }
  }
  
  delay(10);
}

int readNext(char sChar)
{
  // Zero buffer before reading
  memset(data, 0, sizeof(data));

  // Read next set of data
  if (Serial.available() > 0)
  {
    return Serial.readBytesUntil(sChar, data, sizeof(data));
  }
}

void parseReceived()
{
  if (data == 'F')
    sendFile();
  else if (data == 'M')
    setMode();
}

void sendFile()
{
  
}

void setMode()
{
  // Get mode setting char
  char m = Serial.read();

  // Parse mode setting
  if (m == 'T')
    modeTX();
  else if (m == 'R')
    modeRX();
  else if (m == 'X')
    modeTXRX();
  else
    modeNONE();
}

ISR (TIMER1_COMPA_vect)
{
  fired = true;
}



