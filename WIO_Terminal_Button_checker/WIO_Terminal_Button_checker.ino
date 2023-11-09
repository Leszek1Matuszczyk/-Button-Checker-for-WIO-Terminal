#include "Free_fonts.h" // Attach this header file to your sketch to use the GFX Free Fonts. You can write
                        // sketches without it, but it makes referencing them easier.
#include "SPI.h"        // Include the SPI library.
#include "Tft_eSPI.h"   // Attach this header file to your sketch to use the Arduino TFT graphics library targeted at ESP8266
    and ESP32 based board. You can write
                        // sketches without it, but it makes referencing them easier.
TFT_eSPI tft = TFT_eSPI(); // Create an instance of the TFT_eSPI library.

// Variables for button states and labels
bool aButtonAct[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }; // Array to store the current state of buttons
bool aButtonSav[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }; // Array to store the last state of buttons
String tekst[8] = { "A button", "B button", "C button", "Up button", "Left button", "Right button", "Down button", "5wayPress button" }; // Array to store button labels
int cursY = 0; // Variable used for cursor positioning

void setup() {
  Serial.begin(9600); // Initialize the serial communication at a baud rate of 9600.
  tft.begin(); // Initialize the LCD screen.
  tft.setRotation(3); // Set the screen orientation.

  // Button pin configurations (buttons are wired to pins from 28 to 35)
  pinMode(WIO_KEY_A, INPUT_PULLUP);
  pinMode(WIO_KEY_B, INPUT_PULLUP);
  pinMode(WIO_KEY_C, INPUT_PULLUP);
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);

  tft.fillRect(0, 0, 320, 240, TFT_BLACK); // Clear the screen by filling it with black.

  // Display the initial state of the buttons
  for (int i = 0; i < 8; i++) {
    cursY = i + 1;
    tft.setCursor(0, cursY * 12); // Set the cursor position for text display.
    aButtonAct[i] = digitalRead(28 + i); // Read the current state of the button.
    Serial.print(aButtonAct[i]);
    Serial.println(aButtonSav[i]);
    if (aButtonAct[i] != aButtonSav[i]) {
      tft.setTextColor(TFT_WHITE); // Set text color to white.
      tft.setFreeFont(FF1); // Set the font for text display.
      tft.print(tekst[i]); // Display the button label.

      // Check if the button is pressed (LOW) or released (HIGH) and display accordingly.
      if (digitalRead(28 + i) == LOW) {
        tft.fillRect(tft.getCursorX(), tft.getCursorY() - 10, 40, 11, TFT_GREEN); // Highlight with green for ON state.
        tft.print("ON  ");
      } else {
        tft.fillRect(tft.getCursorX(), tft.getCursorY() - 10, 40, 11, TFT_RED); // Highlight with red for OFF state.
        tft.print("OFF");
      }
      tft.println(); // Move to the next line.

      aButtonSav[i] = aButtonAct[i]; // Update the last state with the current state.
    }
  }
}

void loop() {
  // Continuously monitor and update the button states and display.
  for (int i = 0; i < 8; i++) {
    cursY = i + 1;
    tft.setCursor(0, cursY * 12);
    aButtonAct[i] = digitalRead(28 + i); // Read the current state of the button.
    Serial.print(aButtonAct[i]);
    Serial.println(aButtonSav[i]);
    if (aButtonAct[i] != aButtonSav[i]) {
      tft.setTextColor(TFT_WHITE); // Set text color to white.
      tft.setFreeFont(FF1); // Set the font for text display.
      tft.print(tekst[i]); // Display the button label.

      // Check if the button is pressed (LOW) or released (HIGH) and display accordingly.
      if (digitalRead(28 + i) == LOW) {
        tft.fillRect(tft.getCursorX(), tft.getCursorY() - 10, 40, 11, TFT_GREEN); // Highlight with green for ON state.
        tft.print("ON  ");
      } else {
        tft.fillRect(tft.getCursorX(), tft.getCursorY() - 10, 40, 11, TFT_RED); // Highlight with red for OFF state.
        tft.print("OFF");
      }
      tft.println(); // Move to the next line.

      aButtonSav[i] = aButtonAct[i]; // Update the last state with the current state.
    }
  }
}