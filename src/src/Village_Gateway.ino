/*
 * Project: Vajra Vachan - Village Gateway Node
 * Function: Receives LoRa alerts from Forest Nodes and bridges data to 
 * the Blynk IoT Cloud dashboard via Wi-Fi for real-time monitoring.
 */

#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "Vajra Vachan Gateway"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN" // Kept private

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <SPI.h>
#include <LoRa.h>

// Wi-Fi Credentials (Sanitized)
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// LoRa Pins
#define LORA_SS 18
#define LORA_RST 14
#define LORA_DIO0 26

void setup() {
  Serial.begin(115200);

  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Initialize LoRa
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("Village Gateway Active. Listening for Forest Nodes...");
}

void loop() {
  Blynk.run();

  // Check for incoming LoRa packets
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String incomingMessage = "";
    while (LoRa.available()) {
      incomingMessage += (char)LoRa.read();
    }
    
    Serial.print("Received Alert: ");
    Serial.println(incomingMessage);

    // If alert matches, push notification to Blynk Dashboard
    if (incomingMessage.indexOf("ALERT: ELEPHANT_DETECTED") >= 0) {
      triggerBlynkAlert();
    }
  }
}

void triggerBlynkAlert() {
  // Pushing high signal to Virtual Pin 1 (LED Alert on Dashboard)
  Blynk.virtualWrite(V1, 255); 
  
  // Log event to terminal widget on Virtual Pin 2
  Blynk.virtualWrite(V2, "CRITICAL: Herd detected at Forest Boundary!\n");
  
  // Turn off LED after 5 seconds
  delay(5000);
  Blynk.virtualWrite(V1, 0); 
}
