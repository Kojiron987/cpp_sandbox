#include "LedDriver.h"

#include <cstdint>

#include "util/RuntimeError.h"

namespace tdd::led_driver {

  enum class LedRange {
    kFirst = 1,
    kLast = 16,
  };

  LedDriver::LedDriver(uint16_t* address) {
    leds_address_ = address;
    leds_image_ = static_cast<uint16_t>(LedStatus::kAllLedsOff);
    UpdateHardware();
  }

  bool LedDriver::IsOn(int led_number) {
    if (IsLedOutOfBounds(led_number)) {
      return false;
    }
    
    return 0 != (leds_image_ & ConvertLedNumberToBit(led_number));
  }

  bool LedDriver::IsOff(int led_number) {
    return !IsOn(led_number);
  }

  void LedDriver::TurnOn(int led_number) {
    if (IsLedOutOfBounds(led_number)) {
      RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
      return;
    }

    SetLedImageBit(led_number);
    UpdateHardware();
  }

  void LedDriver::TurnOff(int led_number) {
    if (IsLedOutOfBounds(led_number)) {
      return;
    }
    
    ClearLedImageBig(led_number);
    UpdateHardware();
  }

  void LedDriver::TurnAllOn() {
    leds_image_ = static_cast<uint16_t>(tdd::led_driver::LedStatus::kAllLedsOn); 
    UpdateHardware();
  }

  void LedDriver::TurnAllOff() {
    leds_image_ = static_cast<uint16_t>(tdd::led_driver::LedStatus::kAllLedsOff);
    UpdateHardware();
  }

  uint16_t LedDriver::ConvertLedNumberToBit(int led_number) {
    return static_cast<uint16_t>(1 << (led_number - 1));
  }

  void LedDriver::UpdateHardware(void) {
    *leds_address_ = leds_image_;
  }

  bool LedDriver::IsLedOutOfBounds(int led_number) {
    return led_number < static_cast<int>(LedRange::kFirst) || 
           static_cast<int>(LedRange::kLast) < led_number;
  } 

  void LedDriver::SetLedImageBit(int led_number) {
    leds_image_ |= ConvertLedNumberToBit(led_number);
  }

  void LedDriver::ClearLedImageBig(int led_number) {
    leds_image_ &= ~(ConvertLedNumberToBit(led_number));
  }
}
