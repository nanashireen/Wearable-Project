#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor's DATA pin
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test Program");
  dht.begin();
}

void loop() {
  delay(2000); // Wait a few seconds between measurements

  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Send the temperature to Processing
  Serial.print("T=");
  Serial.println(t);
}