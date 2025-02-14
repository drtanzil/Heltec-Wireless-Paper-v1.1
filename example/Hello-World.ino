#include "Arduino.h"
#include <Wire.h>
#include "HT_lCMEN2R13EFC1.h"

// Initialize the OLED display (modify pins if needed)
HT_ICMEN2R13EFC1 display(6, 5, 4, 7, 3, 2, -1, 6000000); 

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Hello World...");

  VextON();         // Enable external power for OLED
  delay(100);       // Stabilize power
  SPI.begin();      // Initialize SPI bus
  display.init();   // Initialize OLED display
  display.clear();

  // Display "Hello, World!"
  display.drawString(50, 30, "Hello, World!");  
  display.update(BLACK_BUFFER);
  display.display();
}

void loop() {
  // Nothing to do here, display remains static
}

// Power Management Functions
void VextON() {
  pinMode(45, OUTPUT);
  digitalWrite(45, LOW);
}

void VextOFF() { // Default OFF
  pinMode(45, OUTPUT);
  digitalWrite(45, HIGH);
}