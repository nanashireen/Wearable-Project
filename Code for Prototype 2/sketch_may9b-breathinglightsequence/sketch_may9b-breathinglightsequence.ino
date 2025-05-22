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
  // Breathe effect for all LEDs simultaneously
  for (int i = 0; i < 255; i++) {
    analogWrite(LED1, i);
    analogWrite(LED2, i);
    analogWrite(LED3, i);
    analogWrite(LED4, i);
    analogWrite(LED5, i);
    analogWrite(LED6, i);
    analogWrite(LED7, i);
    delay(5);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(LED1, i);
    analogWrite(LED2, i);
    analogWrite(LED3, i);
    analogWrite(LED4, i);
    analogWrite(LED5, i);
    analogWrite(LED6, i);
    analogWrite(LED7, i);
    delay(5);
  }

  delay(500); // Pause before repeating
}