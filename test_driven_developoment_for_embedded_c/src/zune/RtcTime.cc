#include "zune/RtcTime.h"

bool IsLeapYear(int year) {
  if (year % 400 == 0) {
    return true;
  }

  if (year % 100 == 0 && year % 400 != 0) {
    return false;
  }

  return year % 4 == 0;
}

void SetYearAndDayOfYear(RtcTime* time) {
  int days = time->daysSince1980;
  int year = kStartingYear;

  while (days > 365) {
    if (IsLeapYear(year)) {
      if (days > 366) {
        days -= 366;
        year += 1;
      } else {
        days -= 365;
        year += 1;
      }
    }
    time->dayOfYear = days;
    time->year = year;
  }
}
