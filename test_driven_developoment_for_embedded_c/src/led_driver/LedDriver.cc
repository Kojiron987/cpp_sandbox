#include "LedDriver.h"

#include <cstdint>

namespace tdd::led_driver {
  LedDriver::LedDriver(uint16_t* address) {
    led_address_ = address;
    *led_address_ = 0;
  }

  void LedDriver::TurnOn(int led_number) {
     *led_address_ |= ConvertLedNumberToBit(led_number);
  }

  void LedDriver::TurnOff(int led_number) {
     *led_address_ &= ~(ConvertLedNumberToBit(led_number));
  }

  void LedDriver::TurnAllOn() {
    *led_address_ = static_cast<uint16_t>(tdd::led_driver::LedStatus::kAllLedsOn); 
  }

  void LedDriver::TurnAllOff() {
    *led_address_ = static_cast<uint16_t>(tdd::led_driver::LedStatus::kAllLedsOff);
  }

  uint16_t LedDriver::ConvertLedNumberToBit(int led_number) {
    return 1 << (led_number - 1);
  }
}
