struct RtcTime {
  int daysSince1980;
  int year;
  int dayOfYear;
};

constexpr int kStartingYear = 1980;

static bool IsLeapYear(int year);
static void SetYearAndDayOfYear(RtcTime* time);
