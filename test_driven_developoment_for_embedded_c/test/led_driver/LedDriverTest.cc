#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "led_driver/LedDriver.h"
#include "mocks/RuntimeErrorStub.h"

using namespace tdd::led_driver;

TEST_GROUP(LedDriver_Test) {
  uint16_t virtualleds_ = 0xffff;
  LedDriver* driver_;

  void setup() {
    driver_ = new LedDriver(&virtualleds_);
  }
  
  void teardown() {
    delete driver_;
    driver_ = nullptr;
  }
};

TEST(LedDriver_Test, LedsOffAfterCreate) {
  LONGS_EQUAL(0, virtualleds_);
}

TEST(LedDriver_Test, TurnOnLedOne) {
  driver_->TurnOn(1);
  LONGS_EQUAL(1, virtualleds_);
}

TEST(LedDriver_Test, TurnOffLedOne) {
  driver_->TurnOn(1);
  driver_->TurnOff(1);
  LONGS_EQUAL(0, virtualleds_);
}

TEST(LedDriver_Test, TurnOnMultipleLeds) {
  driver_->TurnOn(9);
  driver_->TurnOn(8);
  LONGS_EQUAL(0x0180, virtualleds_);
}

TEST(LedDriver_Test, TurnOffMultipleLeds) {
  driver_->TurnAllOn();
  driver_->TurnOff(9);
  driver_->TurnOff(8);
  LONGS_EQUAL((~0x180)&0xffff, virtualleds_);
}

TEST(LedDriver_Test, TurnOffAnyLeds) {
  driver_->TurnOn(9);
  driver_->TurnOn(8);
  driver_->TurnOff(8);
  LONGS_EQUAL(0x0100, virtualleds_);
}

TEST(LedDriver_Test, TurnAllOn) {
  driver_->TurnAllOn();
  LONGS_EQUAL(0xffff, virtualleds_);
}

TEST(LedDriver_Test, TurnAllOff) {
  driver_->TurnAllOff();
  LONGS_EQUAL(0x0000, virtualleds_);
}

TEST(LedDriver_Test, LedMemoryIsNotReadable) {
  virtualleds_ = 0xffff;
  driver_->TurnOn(8);
  LONGS_EQUAL(0x80, virtualleds_);
}

TEST(LedDriver_Test, UpperAndLowerBounds) {
  driver_->TurnOn(1);
  driver_->TurnOn(16);
  LONGS_EQUAL(0x8001, virtualleds_);
}

TEST(LedDriver_Test, OutOfBoundsTurnOnChangesNothing) {
  driver_->TurnOn(-1);
  driver_->TurnOn(0);
  driver_->TurnOn(17);
  driver_->TurnOn(3142);
  LONGS_EQUAL(0x0, virtualleds_);
}

TEST(LedDriver_Test, OutOfBoundsTurnOffChangesNothing) {
  driver_->TurnOff(-1);
  driver_->TurnOff(0);
  driver_->TurnOff(17);
  driver_->TurnOff(3142);
  LONGS_EQUAL(0x0, virtualleds_);
}

TEST(LedDriver_Test, OutOfBoundsProducesRuntimeError) {
  driver_->TurnOn(-1);
  STRCMP_EQUAL("LED Driver: out-of-bounds LED",
      RuntimeErrorStub_GetLastError());
  LONGS_EQUAL(-1, RuntimeErrorStub_GetLastParamter());
}

TEST(LedDriver_Test, IsOn) {
  CHECK_FALSE(driver_->IsOn(11));
  driver_->TurnOn(11);
  CHECK_TRUE(driver_->IsOn(11));
  CHECK_FALSE(driver_->IsOn(12));
}

TEST(LedDriver_Test, OutOfBoundsAlwaysOff) {
  CHECK_FALSE(driver_->IsOn(0));
  CHECK_FALSE(driver_->IsOn(17));
  CHECK_TRUE(driver_->IsOff(0));
  CHECK_TRUE(driver_->IsOff(17));
}

TEST(LedDriver_Test, IsOff) {
  CHECK_TRUE(driver_->IsOff(11));
  driver_->TurnOn(11);
  driver_->TurnOn(12);
  driver_->TurnOff(11);
  CHECK_TRUE(driver_->IsOff(11));
  CHECK_FALSE(driver_->IsOff(12));
}

