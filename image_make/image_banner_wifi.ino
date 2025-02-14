#include "HT_lCMEN2R13EFC1.h"
#include "images.h"
// Initialize the display (modify pin numbers as needed)
HT_ICMEN2R13EFC1 display(6, 5, 4, 7, 3, 2, -1, 6000000);
void setup() {
  Serial.begin(115200);
  Serial.println("Starting Wi-Fi Logo...");
  VextON();         // Enable external power for OLED
  delay(100);       // Stabilize power
  SPI.begin();      // Initialize SPI bus
  display.init();   // Initialize e-paper display
  display.clear();  
  // Display the Wi-Fi logo
  drawImage();
}
void loop() {
  // Nothing to do here, display remains static
}
void drawImage() {
  Serial.println("Displaying Wi-Fi Logo...");
  // Clear the screen
  display.clear();
  // display.update(BLACK_BUFFER);
  // Calculate the X and Y coordinates to center the image
  int x = (display.width() - WiFi_Logo_width) / 2;
  int y = (display.height() - WiFi_Logo_height) / 2;
  // Draw the image at the calculated (x, y) position
  display.drawXbm(x, y, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
  display.update(BLACK_BUFFER);
  display.display();
}
void VextON() {
  pinMode(45, OUTPUT);
  digitalWrite(45, LOW);
}
void VextOFF() { // Default OFF
  pinMode(45, OUTPUT);
  digitalWrite(45, HIGH);
}