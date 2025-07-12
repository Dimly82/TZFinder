#include <gtest/gtest.h>

#include "TimezoneFinder.h"

TEST(TimezoneTest, Moscow) {
  TimezoneInfo exp = {"Europe/Moscow", 3};
  TimezoneInfo res = TimezoneFinder::GetTimezone(55.7558, 37.6176);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Omsk) {
  TimezoneInfo exp = {"Asia/Omsk", 6};
  TimezoneInfo res = TimezoneFinder::GetTimezone(54.9893, 73.3682);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Kaliningrad) {
  TimezoneInfo exp = {"Europe/Kaliningrad", 2};
  TimezoneInfo res = TimezoneFinder::GetTimezone(54.7101, 20.5101);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Sakhalin) {
  TimezoneInfo exp = {"Asia/Sakhalin", 11};
  TimezoneInfo res = TimezoneFinder::GetTimezone(50.3294, 142.7065);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Yekaterinburg) {
  TimezoneInfo exp = {"Asia/Yekaterinburg", 5};
  TimezoneInfo res = TimezoneFinder::GetTimezone(56.8380, 60.5974);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, London) {
  TimezoneInfo exp = {"Europe/London", 0};
  TimezoneInfo res = TimezoneFinder::GetTimezone(51.5074, -0.1278);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, NewYork) {
  TimezoneInfo exp = {"America/New_York", -5.0};
  TimezoneInfo res = TimezoneFinder::GetTimezone(40.7128, -74.0060);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, India) {
  TimezoneInfo exp = {"Asia/Kolkata", 5.5};
  TimezoneInfo res = TimezoneFinder::GetTimezone(28.6139, 77.2090);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Nepal) {
  TimezoneInfo exp = {"Asia/Kathmandu", 5.75};
  TimezoneInfo res = TimezoneFinder::GetTimezone(27.7172, 85.3240);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Newfoundland) {
  TimezoneInfo exp = {"America/St_Johns", -3.5};
  TimezoneInfo res = TimezoneFinder::GetTimezone(47.5615, -52.7126);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}


TEST(TimezoneTest, Yangon) {
  TimezoneInfo exp = {"Asia/Yangon", 6.5};
  TimezoneInfo res = TimezoneFinder::GetTimezone(16.8409, 96.1735);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Darwin) {
  TimezoneInfo exp = {"Australia/Darwin", 9.5};
  TimezoneInfo res = TimezoneFinder::GetTimezone(-12.4634, 130.8456);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Kiritimati) {
  TimezoneInfo exp = {"Pacific/Kiritimati", 14.0};
  TimezoneInfo res = TimezoneFinder::GetTimezone(1.8721, -157.4278);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}
