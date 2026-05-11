/*
 * Project: Vajra Vachan - Forest Edge Node
 * Function: Reads ADXL345 seismic data, filters for heavy wildlife footprint,
 * triggers local PAM8403 bio-acoustic audio, and transmits LoRa alert.
 * Note: Core algorithmic filtering parameters have been sanitized for public repository.
 */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <SPI.h>
#include <LoRa.h>

// Pin Definitions
#define LORA_SS 18
#define LORA_RST 14
#define LORA_DIO0 26
#define AUDIO_TRIGGER_PIN 4 // Pin to trigger PAM8403 amplifier

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// Thresholds (Sanitized)
const float SEISMIC_THRESHOLD = 2.5; // G-force threshold for elephant footfall

void setup() {
  Serial.begin(115200);
  pinMode(AUDIO_TRIGGER_PIN, OUTPUT);
  digitalWrite(AUDIO_TRIGGER_PIN, LOW);

  // Initialize Sensor
  if (!accel.begin()) {
    Serial.println("No ADXL345 detected. Check wiring!");
    while (1);
  }
  accel.setRange(ADXL345_RANGE_16_G);

  // Initialize LoRa
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(433E6)) { // 433 MHz frequency
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("Forest Node Active. Monitoring Seismic Activity...");
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);

  // Basic amplitude check (Proprietary frequency filtering omitted)
  if (abs(event.acceleration.z) > SEISMIC_THRESHOLD) {
    Serial.println("THREAT DETECTED: Seismic Signature Matched.");
    
    // 1. Deploy Bio-Acoustic Deterrent (Honeybee Sound)
    triggerAudioDeterrent();

    // 2. Transmit LoRa Alert to Village
    sendLoRaAlert();
    
    // Cooldown to prevent spamming
    delay(10000); 
  }
  delay(100); // Sampling rate
}

void triggerAudioDeterrent() {
  Serial.println("Deploying Bio-Acoustic Deterrent...");
  digitalWrite(AUDIO_TRIGGER_PIN, HIGH);
  delay(5000); // Play sound for 5 seconds
  digitalWrite(AUDIO_TRIGGER_PIN, LOW);
}

void sendLoRaAlert() {
  Serial.println("Transmitting LoRa packet to Gateway...");
  LoRa.beginPacket();
  LoRa.print("ALERT: ELEPHANT_DETECTED_NODE_1");
  LoRa.endPacket();
}
