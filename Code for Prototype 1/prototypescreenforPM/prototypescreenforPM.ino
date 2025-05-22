#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>
#include <Fonts/FreeSansBold9pt7b.h>

// Define pins for display interface

#if defined(ARDUINO_SEEED_XIAO_RP2040)

// Pinout when using Seed Round Display for XIAO in combination with
// Seeed XIAO RP2040. Other (non-RP2040) XIAO boards, any Adafruit Qt Py
// boards, and other GC9A01A display breakouts will require different pins.
#define TFT_CS D1 // Chip select
#define TFT_DC D3 // Data/command
#define TFT_BL D6 // Backlight control

#else // ALL OTHER BOARDS - EDIT AS NEEDED

// Other RP2040-based boards might not have "D" pin defines as shown above
// and will use GPIO bit numbers. On non-RP2040 boards, you can usually use
// pin numbers silkscreened on the board.
#define TFT_DC  7
#define TFT_CS 10
// If display breakout has a backlight control pin, that can be defined here
// as TFT_BL. On some breakouts it's not needed, backlight is always on.

#endif

// Display constructor for primary hardware SPI connection -- the specific pins used for writing to the display are unique to each board and are not
// negotiable. "Soft" SPI (using any pins) is an option but performance is reduced; it's rarely used, see header file for syntax if needed.
Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

// Define colors
#define BLACK 0x0000
#define WHITE 0xFFFF
#define BLUE 0x001F
#define LIGHTBLUE 0xADD8
#define DARKGRAY 0x5A5A

void setup() {
  Serial.begin(9600);
  Serial.println("GC9A01A Custom Display");

  tft.begin();
  tft.fillScreen(LIGHTBLUE); // Set background to light blue

#if defined(TFT_BL)
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH); // Backlight on
#endif // end TFT_BL

  // Set text font
  tft.setFont(&FreeSansBold9pt7b);
  tft.setTextColor(BLACK);
  tft.setTextSize(1);

  // Display Time
  tft.setCursor(tft.width() / 2 - (6 * 9 / 2), 30); // Adjust position based on font size
  tft.print("15:27");

  // Display Date
  tft.setFont(NULL); // Use default font for date
  tft.setTextSize(1);
  tft.setCursor(tft.width() / 2 - (7 * 6 / 2), 50); // Adjust position based on font size
  tft.print("1st July 2025");

  // Display Settings Icon
  tft.setTextSize(2);
  tft.setCursor(tft.width() - 30, 25);
  tft.print("\u2699"); // Unicode for gear icon

  // Stress Levels Text
  tft.setFont(&FreeSansBold9pt7b);
  tft.setTextSize(1);
  tft.setCursor(30, 90);
  tft.print("Stress");
  tft.setCursor(30, 105);
  tft.print("Levels");

  // Draw Stress Level Circle
  int16_t cx = tft.width() - 60;
  int16_t cy = 110;
  uint16_t radius = 30;
  tft.drawCircle(cx, cy, radius, DARKGRAY);

  // Draw Arc for Stress Level (23/100)
  float percentage = 23.0 / 100.0;
  float endAngle = 2 * PI * percentage - PI / 2; // Start from top
  int16_t innerRadius = radius - 5;

  for (int16_t i = 0; i <= 60; i++) {
    float angle = (2 * PI * i / 60.0) - PI / 2;
    if (angle <= endAngle) {
      int16_t x = cx + innerRadius * cos(angle);
      int16_t y = cy + innerRadius * sin(angle);
      tft.drawPixel(x, y, BLUE);
      int16_t outerX = cx + radius * cos(angle);
      int16_t outerY = cy + radius * sin(angle);
      tft.drawPixel(outerX, outerY, BLUE);
    }
  }

  // Display Stress Level Value
  tft.setFont(&FreeSansBold9pt7b);
  tft.setTextSize(2);
  String stressValue = "23";
  tft.setCursor(cx - 15, cy - 5); // Approximate centering based on typical character width
  tft.print(stressValue);

  tft.setFont(NULL); // Use default font for /100
  tft.setTextSize(1);
  tft.setCursor(cx + 18, cy); // Approximate positioning for /100
  tft.print("/100");
}

void loop() {
  delay(1000);
}