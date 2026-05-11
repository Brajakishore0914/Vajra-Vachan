# 🐘 Vajra Vachan
**Decentralized Seismic Intelligence Network for Safe Human-Elephant Co-existence**

![Vajra Vachan Architecture](link_to_your_architecture_image_here.jpg)

## 📌 Project Overview
Vajra Vachan is an intelligent, early-warning deterrence system engineered to solve severe human-elephant conflicts in rural areas. Instead of relying on harmful high-voltage electric fences or unreliable optical sensors, this Industrial IoT (IIoT) project creates an **"invisible sensory border"** using seismic intelligence and private LoRa networks.

## ⚙️ Key Features
* **Proactive Seismic Intelligence:** Utilizes an ADXL345 accelerometer to detect the low-frequency, heavy seismic footprint of an approaching elephant herd, algorithmically filtering out false positives from wind or smaller animals.
* **Decentralized LPWAN Architecture:** Operates on a private LoRa (433MHz) spread-spectrum mesh network. It guarantees long-range communication through dense forest canopies without the need for vulnerable GSM cellular towers.
* **Safe Bio-Acoustic Deterrence:** Replaces physical trauma with psychological safety. The edge node deploys high-fidelity audio (such as agitated honeybees) via a DAC and PAM8403 amplifier to trigger a natural flight response.
* **Real-Time IoT Command:** Bridges the edge network to the cloud. An integrated Blynk IoT dashboard allows authorities to monitor real-time threat data, battery telemetry, and network strength.

## 🛠️ Hardware Components
* **Microcontroller:** ESP32 (Dual-core Edge Processor)
* **Seismic Sensor:** ADXL345 3-Axis Accelerometer
* **Communication:** LoRa Transceiver Module (433MHz)
* **Audio Deterrent:** PAM8403 Amplifier + Speaker + SD Card Module
* **Power:** Solar Panel & Li-ion Battery with TP4056 module

## 💻 Software & Platforms
* **Language:** C++ (Arduino Framework)
* **IoT Dashboard:** Blynk 2.0
* **Libraries:** `LoRa.h`, `Adafruit_ADXL345.h`, `BlynkSimpleEsp32.h`

## 🚀 Setup Instructions
1. Clone this repository: `git clone https://github.com/YourUsername/Vajra-Vachan.git`
2. Open the `/src` folder in the Arduino IDE.
3. Install the required libraries via the Library Manager.
4. **Important:** Add your own Blynk Auth Token and Wi-Fi credentials in the designated placeholder fields before compiling.
5. Flash the "Forest Node" code to your primary ESP32, and the "Village Gateway" code to your secondary ESP32.

---
*Built with passion for wildlife conservation and agricultural sustainability by the Zenith Squad.*
