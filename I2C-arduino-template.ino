#include "I2C_scanner.hpp"

#include <LiquidCrystal_I2C.h>

byte location = 0; // [0, 7]
byte omega[8] = {B00000, B01110, B10001, B10001, B10001, B01010, B11011, B00000};

uint8_t lcd_addr = 0x00;
uint8_t lcd_rows = 2;
uint8_t lcd_cols = 16;

I2CScanner scan;

void setup() {
  scan.initialization();
  scan.exec(lcd_addr);

  LiquidCrystal_I2C lcd(lcd_addr, lcd_rows, lcd_cols);

  // Example Code
  lcd.init();
  lcd.backlight();

  lcd.createChar(location, omega);
  lcd.home();

  lcd.print("I2C Template ");
  lcd.write(location);

  delay(5000);
  lcd.clear();
}

void loop() {

}
