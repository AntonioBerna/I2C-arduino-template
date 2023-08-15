#include "I2C_scanner.hpp"

#include <LiquidCrystal_I2C.h>

uint8_t location = 0; // [0, 7]
uint8_t omega[] = {0x0, 0xE, 0x11, 0x11, 0x11, 0xA, 0x1B, 0x0};

uint8_t lcd_addr = 0x0;
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
