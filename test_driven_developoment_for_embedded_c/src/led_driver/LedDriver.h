#pragma once

#include<cstdint>

namespace tdd::led_driver {

  enum class LedStatus {
    kAllLedsOn = static_cast<uint16_t>(~0),
    kAllLedsOff = static_cast<uint16_t>(~kAllLedsOn),
  };

  class LedDriver {
    public:
      LedDriver(uint16_t* address);
      bool IsOn(int led_number);
      bool IsOff(int led_number);
      void TurnOn(int led_number);
      void TurnAllOn();
      void TurnOff(int led_number);
      void TurnAllOff();
    private:
      uint16_t* leds_address_;
      uint16_t leds_image_;

      uint16_t ConvertLedNumberToBit(int led_number);
      void UpdateHardware(void);
      bool IsLedOutOfBounds(int led_number);
      void SetLedImageBit(int led_number);
      void ClearLedImageBig(int led_number);
  };
}
