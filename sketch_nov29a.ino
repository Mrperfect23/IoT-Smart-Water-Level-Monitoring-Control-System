// --- 1. BLYNK CONFIGURATION ---
#define BLYNK_TEMPLATE_ID "TMPL3oC3Xl0g6"
#define BLYNK_TEMPLATE_NAME "Irrigation"
#define BLYNK_AUTH_TOKEN "5OcZZodNaWYfsgtQeGR6S1Bc9UlM_Vf3"

// --- 2. LIBRARIES ---
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// --- 3. WIFI DETAILS ---
char ssid[] = "OnePlus NordCE 5G"; 
char pass[] = "password";

// --- 4. PINS (UPDATED FOR STABILITY) ---
#define RELAY_PIN D1
#define DHTPIN    D2    // ⚠️ Maine D4 se D2 kar diya hai (Wiring change karna)
#define SOIL_PIN  A0

#define DHTTYPE   DHT11
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// --- 5. SENSOR FUNCTION ---
void sendSensorData() {

  // A. Soil Moisture
  int sensorValue = analogRead(SOIL_PIN);
  int soilPercent = map(sensorValue, 1024, 300, 0, 100);
  soilPercent = constrain(soilPercent, 0, 100);

  // B. Temperature & Humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Error Checking
  if (isnan(h) || isnan(t)) {
    Serial.println("DHT read failed! Check Wiring (D2).");
  } else {
    // C. Send to Blynk ONLY if reading is good
    Blynk.virtualWrite(V2, t);
    Blynk.virtualWrite(V3, h);
    
    // Serial Debug
    Serial.print("Temp: "); Serial.print(t);
    Serial.print("°C | Humidity: "); Serial.println(h);
  }

  // Send Soil Data
  Blynk.virtualWrite(V1, soilPercent);
  Serial.print("Soil: "); Serial.print(soilPercent);
  Serial.println("%");
  
  // ❌ YAHAN SE 'delay(1500)' HATA DIYA HAI
}

// --- 6. SETUP ---
void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2500L, sendSensorData);  // Har 2.5 sec mein data bhejega
}

// --- 7. LOOP ---
void loop() {
  Blynk.run();
  timer.run();
}