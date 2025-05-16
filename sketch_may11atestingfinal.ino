#include <DHT.h>

#define DHTPIN 2     // Digital pin connected to the DHT11 sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 11;
const int LED4 = 10;
const int LED5 = 9;
const int LED6 = 8;
const int LED7 = 7;

float previousTemperature = -100.0; // Initialize with a very low value
unsigned long lastTemperatureReadTime = 0;
const unsigned long temperatureReadInterval = 1500; // Check temperature more often (1.5 seconds)
const float rapidTemperatureIncreaseThreshold = 0.2; // Temperature increase in Celsius
const unsigned long sequenceDuration = 60000; // 1 minute in milliseconds
unsigned long sequenceStartTime = 0;
bool sequenceActive = false;

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

  if (sequenceActive) {
    if (currentTime - sequenceStartTime < sequenceDuration) {
      playRepeatingLEDSequence();
    } else {
      sequenceActive = false;
      turnOffAllLEDs();
    }
    return; // Skip temperature reading while the sequence is active
  }

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

    // Send the temperature to Processing
    Serial.print(currentTemperature);
    Serial.print("\n"); // Send a newline character to mark the end of the data

    if (previousTemperature != -100.0) {
      float temperatureDifference = currentTemperature - previousTemperature;
      Serial.print("Temperature difference: ");
      Serial.print(temperatureDifference);
      Serial.println(" *C");

      if (temperatureDifference > rapidTemperatureIncreaseThreshold) {
        Serial.println("Rapid temperature increase detected! Starting LED sequence for 1 minute.");
        Serial.println("ALERT"); // Send "ALERT" to Processing
        playLEDSequence(); // Play the initial trigger sequence
        sequenceActive = true;
        sequenceStartTime = currentTime;
      }
    }
    previousTemperature = currentTemperature;
  }
}

void playLEDSequence() {
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

void playRepeatingLEDSequence() {
  // Light up LED7 instantly
  digitalWrite(LED7, HIGH);
  delay(250);

  // Gradually light up LEDs 6, 5, 4, 3, 2, 1 in sequence
  for (int i = 0; i < 256; i++) {
    analogWrite(LED6, i);
    delay(5);
  }
  for (int i = 0; i < 256; i++) {
    analogWrite(LED5, i);
    delay(5);
  }
  for (int i = 0; i < 256; i++) {
    analogWrite(LED4, i);
    delay(5);
  }
  for (int i = 0; i < 256; i++) {
    analogWrite(LED3, i);
    delay(5);
  }
  for (int i = 0; i < 256; i++) {
    analogWrite(LED2, i);
    delay(5);
  }
  for (int i = 0; i < 256; i++) {
    analogWrite(LED1, i);
    delay(5);
  }

  delay(250); // Keep all LEDs on for a moment

  // Gradually turn off LEDs 1, 2, 3, 4, 5, 6 in sequence
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED1, i);
    delay(5);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED2, i);
    delay(5);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED3, i);
    delay(5);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED4, i);
    delay(5);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED5, i);
    delay(5);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED6, i);
    delay(5);
  }

  // Turn off LED7 instantly
  digitalWrite(LED7, LOW);
  delay(250); // Shorter delay before repeating
}

void turnOffAllLEDs() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
}
