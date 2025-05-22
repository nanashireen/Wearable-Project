int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;
int LED6 = 8;
int LED7 = 7;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
}

void loop() {
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