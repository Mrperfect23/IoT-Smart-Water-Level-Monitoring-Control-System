# IoT Based Plant Monitoring System 🌱📱

## 📖 Introduction
This is an IoT-based project designed to monitor the health of plants. It uses the **NodeMCU ESP8266** microcontroller to read real-time data from a **Soil Moisture Sensor** and a **DHT11 Temperature & Humidity Sensor**. The data is sent to a mobile application (Blynk/IoT Cloud) over Wi-Fi, allowing users to monitor their plants remotely from anywhere.

## 🚀 Features
- **Real-time Monitoring:** Live tracking of Soil Moisture, Temperature, and Humidity.
- **Wi-Fi Connectivity:** Connects to the internet using NodeMCU ESP8266.
- **Mobile Dashboard:** Visualizes data on a Smartphone App.
- **Compact Design:** Powered directly via USB (5V).

## 🛠️ Hardware Components
1. **NodeMCU ESP8266 (v3)** - Main Controller
2. **Soil Moisture Sensor** - To detect water content in soil
3. **DHT11 Sensor** - Temperature & Humidity Sensor
4. **Micro USB Cable** - For Power Supply & Programming
5. **Jumper Wires** (Male-to-Female)

## 🔌 Pin Connections

| Component | Component Pin | NodeMCU Pin |
|-----------|--------------|-------------|
| **DHT11** | Signal (DATA) | D4 (GPIO 2) |
|           | VCC (+)      | 3V3         |
|           | GND (-)      | GND         |
| **Soil Sensor** | Analog (A0) | A0          |
|                 | VCC (+)     | 3V3         |
|                 | GND (-)     | GND         |

*(Note: The NodeMCU is powered via the Micro-USB port connected to a laptop or phone charger.)*

## ⚙️ How to Run
1. Connect the sensors to the NodeMCU as per the pin table above.
2. Install the **Blynk** (or your preferred IoT) library and **DHT** library in Arduino IDE.
3. Update the code with your:
   - Wi-Fi SSID (Name)
   - Wi-Fi Password
   - API Key / Auth Token
4. Upload the code to the NodeMCU board.
5. Open the Serial Monitor (Baud Rate: 9600) to view the data locally or check your Mobile App.

## 📸 Project Structure
- `src/` - Contains the Arduino Code (.ino file)
- `diagrams/` - Circuit diagrams and Pinout images

---
*Created by Rahul Kumar*
