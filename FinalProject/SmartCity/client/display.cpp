#include <Wire.h>
#include <Arduino.h>
#include "libraries/LiquidCrystal/src/LiquidCrystal.h"


void displayMessage(char message) {
  Serial.println("Display shows: " + message);
  lcd.setCursor(0, 0);
  lcd.print(message);
  delay(2000);
  lcd.clear();
}
