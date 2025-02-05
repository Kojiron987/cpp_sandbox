#pragma once

#include<cstdint>

namespace tdd::led_driver {
  class LedDriver {
    public:
      LedDriver(uint16_t* address);
      void TurnOn(int ledNumber);
      void TurnOff(int ledNumber);
    private:
      uint16_t* led_address_;
  };
}
