#include "CppUTest/TestHarness.h"

TEST_GROUP(RtcTime) {};

TEST(RtcTime, 2008_12_31_last_day_of_leap_year) {
  int yearsStart = daysSince1980ForYear(2008); 
  rtcTime = RtcTime_Create(yearsStart+366);
  assertDate(2008, 12, 31, Wednewsday);
}
