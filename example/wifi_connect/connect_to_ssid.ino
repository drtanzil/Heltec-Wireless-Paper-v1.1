#include <WiFi.h>

const char* ssid = "ISLAM";        // Your WiFi SSID
const char* password = "12345678"; // Your WiFi password

void setup() {
  Serial.begin(115200); // Start serial communication for debugging

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password); // Start the Wi-Fi connection

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 10) {
    delay(1000);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.print("Connected to WiFi! IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println();
    Serial.println("Failed to connect to WiFi.");
  }
}

void loop() {
  // Nothing to do in the loop for now
}
