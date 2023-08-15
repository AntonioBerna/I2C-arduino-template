#pragma once

class I2CScanner {
  public:
    void initialization();
    void exec(uint8_t &lcd_addr);
};
