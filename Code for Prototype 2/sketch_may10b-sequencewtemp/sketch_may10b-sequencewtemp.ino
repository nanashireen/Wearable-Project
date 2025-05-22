#include <DHT.h>

#define DHTPIN 2     // Digital pin connected to the DHT11 sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;
int LED6 = 8;
int LED7 = 7;

float previousTemperature = -100.0; // Initialize with a very low value
unsigned long lastTemperatureReadTime = 0;
const unsigned long temperatureReadInterval = 1500; // Check temperature more often (1.5 seconds)
const float rapidTemperatureIncreaseThreshold = 0.2; // Temperature increase in Celsius

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);

  // Initialize all LEDs off
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastTemperatureReadTime >= temperatureReadInterval) {
    lastTemperatureReadTime = currentTime;
    float currentTemperature = dht.readTemperature();

    if (isnan(currentTemperature)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    Serial.print("Current temperature: ");
    Serial.print(currentTemperature);
    Serial.println(" *C");

    if (previousTemperature != -100.0) {
      float temperatureDifference = currentTemperature - previousTemperature;
      Serial.print("Temperature difference: ");
      Serial.print(temperatureDifference);
      Serial.println(" *C");

      if (temperatureDifference > rapidTemperatureIncreaseThreshold) {
        Serial.println("Rapid temperature increase detected! Starting LED sequence.");
        playLEDSequence();
      }
    }
    previousTemperature = currentTemperature;
  }
}

void playLEDSequence() {
  Serial.print("Temperature when sequence started: ");
  Serial.print(dht.readTemperature()); // Read temperature again when sequence starts
  Serial.println(" *C");

  // Light up LED7 instantly
  digitalWrite(LED7, HIGH);
  delay(150); // Shorter delay for LED7

  // Gradually light up LEDs 6, 5, 4, 3, 2, 1 in sequence
  for (int i = 0; i < 256; i += 8) { // Increase step for faster fade
    analogWrite(LED6, i);
    delay(5); // Shorter fade delay
  }
  for (int i = 0; i < 256; i += 8) {
    analogWrite(LED5, i);
    delay(5);
  }
  for (int i = 0; i < 256; i += 8) {
    analogWrite(LED4, i);
    delay(5);
  }
  for (int i = 0; i < 256; i += 8) {
    analogWrite(LED3, i);
    delay(5);
  }
  for (int i = 0; i < 256; i += 8) {
    analogWrite(LED2, i);
    delay(5);
  }
  for (int i = 0; i < 256; i += 8) {
    analogWrite(LED1, i);
    delay(5);
  }

  delay(150); // Shorter delay for all on

  // Gradually turn off LEDs 1, 2, 3, 4, 5, 6 in sequence
  for (int i = 255; i >= 0; i -= 8) { // Increase step for faster fade
    analogWrite(LED1, i);
    delay(2);
  }
  for (int i = 255; i >= 0; i -= 8) {
    analogWrite(LED2, i);
    delay(2);
  }
  for (int i = 255; i >= 0; i -= 8) {
    analogWrite(LED3, i);
    delay(2);
  }
  for (int i = 255; i >= 0; i -= 8) {
    analogWrite(LED4, i);
    delay(2);
  }
  for (int i = 255; i >= 0; i -= 8) {
    analogWrite(LED5, i);
    delay(2);
  }
  for (int i = 255; i >= 0; i -= 8) {
    analogWrite(LED6, i);
    delay(2);
  }

  // Turn off LED7 instantly
  digitalWrite(LED7, LOW);
  delay(150);
}