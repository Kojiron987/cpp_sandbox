#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "led_driver/LedDriver.h"

using namespace tdd::led_driver;

TEST_GROUP(LedDriver_Test) {
  uint16_t virtualleds_ = 0xffff;
  LedDriver* driver_;

  void setup() {
    LedDriver led(&virtualleds_);
    driver_ = &led;
  }
  
  void teardown() {
    driver_ = nullptr;
  }
};

TEST(LedDriver_Test, LedsOffAfterCreate) {
  BYTES_EQUAL(0, virtualleds_);
}

TEST(LedDriver_Test, TurnOnLedOne) {
  driver_->TurnOn(1);
  BYTES_EQUAL(1, virtualleds_);
}

TEST(LedDriver_Test, TurnOffLedOne) {
  driver_->TurnOn(1);
  driver_->TurnOff(1);
  BYTES_EQUAL(0, virtualleds_);
}

TEST(LedDriver_Test, TurnOnMultipleLeds) {
  driver_->TurnOn(9);
  driver_->TurnOn(8);
  BYTES_EQUAL(0x0180, virtualleds_);
}

