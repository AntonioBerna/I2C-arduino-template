#include "I2C_scanner.hpp"

#include <Wire.h>

void I2CScanner::initialization() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Scanner");
}

void I2CScanner::exec(uint8_t &lcd_addr) {
  byte error, address;
  int found_devices = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; ++address) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      Serial.println(address);
      lcd_addr = address;
      ++found_devices;
    }
  }

  if (found_devices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }
}
