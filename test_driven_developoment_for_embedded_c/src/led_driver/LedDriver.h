#pragma once

#include<cstdint>

namespace tdd::led_driver {

  enum class LedStatus {
    kAllLedsOn = ~0,
    kAllLedsOff = ~kAllLedsOn,
  };

  class LedDriver {
    public:
      LedDriver(uint16_t* address);
      void TurnOn(int led_number);
      void TurnAllOn();
      void TurnOff(int led_number);
      void TurnAllOff();
    private:
      uint16_t* led_address_;

      uint16_t ConvertLedNumberToBit(int led_number);
  };
}
