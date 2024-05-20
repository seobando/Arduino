#include <Wire.h>               //Library required for I2C comms (LCD)
#include <LiquidCrystal_I2C.h>  //Library for LCD display via I2C

void displayMessage(char message) {
  Serial.println("Display shows: " + message);
  lcd.setCursor(0, 0);
  lcd.print(message);
  delay(2000);
  lcd.clear();
}
