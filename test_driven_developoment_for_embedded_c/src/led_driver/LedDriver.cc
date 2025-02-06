#include "led_driver/LedDriver.h"

#include <cstdint>

namespace tdd::led_driver {
  LedDriver::LedDriver(uint16_t* address) {
    led_address_ = address;
    *led_address_ = 0;
  }

  void LedDriver::TurnOn(int ledNumber) {
     *led_address_ |= 1 << (ledNumber-1);
  }

  void LedDriver::TurnOff(int ledNumber) {
     *led_address_ = 0;
  }
}
