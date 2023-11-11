#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C myone(0x27, 16, 2);

void setup() {
  myone.init();
  // myone.backlight(); --> light on
  // myone.noBacklight(); // light off
  myone.backlight();
}

void loop() {
  myone.setCursor(0, 0);
  myone.print("Hello World!!");
  myone.setCursor(0, 1);
  myone.print("^_^");
}