#include <SoftwareSerial.h>

// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial portOne(10, 11);

char* got;
unsigned char recieved, hold;

void setup() {
  // Open serial communications and wait for port to open:
  got = "70";
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // Start each software serial port
  portOne.begin(9600);
  pinMode(9, OUTPUT);
}

char incomingByte;
int n;

void loop() {
 //send data only when you receive data:
    n = atoi(got);
    analogWrite(9,n);
    
    if (Serial.available()) {
      Serial.readBytesUntil('\n',got,10);
      //portOne.write(got);
    }
    delay(20);
    if (portOne.available()) {
      recieved = portOne.read();
      Serial.println(recieved);
      
      hold = recieved;
    }

}
