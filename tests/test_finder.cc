#include <gtest/gtest.h>

#include "TimezoneFinder.h"

TEST(TimezoneTest, Kaliningrad) {
  TimezoneInfo exp = {"Europe/Kaliningrad", 2};
  TimezoneInfo res = TimezoneFinder::GetTimezone(54.7101, 20.5101);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Simferopol) {
  TimezoneInfo exp = {"Europe/Simferopol", 3};
  TimezoneInfo res = TimezoneFinder::GetTimezone(44.9521, 34.1024);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Moscow) {
  TimezoneInfo exp = {"Europe/Moscow", 3};
  TimezoneInfo res = TimezoneFinder::GetTimezone(55.7558, 37.6176);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Volgograd) {
  TimezoneInfo exp = {"Europe/Volgograd", 3};
  TimezoneInfo res = TimezoneFinder::GetTimezone(48.7080, 44.5133);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Astrakhan) {
  TimezoneInfo exp = {"Europe/Astrakhan", 4};
  TimezoneInfo res = TimezoneFinder::GetTimezone(46.3497, 48.0408);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Saratov) {
  TimezoneInfo exp = {"Europe/Saratov", 4};
  TimezoneInfo res = TimezoneFinder::GetTimezone(51.5336, 46.0343);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Ulyanovsk) {
  TimezoneInfo exp = {"Europe/Ulyanovsk", 4};
  TimezoneInfo res = TimezoneFinder::GetTimezone(54.3142, 48.4031);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Samara) {
  TimezoneInfo exp = {"Europe/Samara", 4};
  TimezoneInfo res = TimezoneFinder::GetTimezone(53.2415, 50.2212);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Kirov) {
  TimezoneInfo exp = {"Europe/Kirov", 3};
  TimezoneInfo res = TimezoneFinder::GetTimezone(58.6035, 49.6670);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Yekaterinburg) {
  TimezoneInfo exp = {"Asia/Yekaterinburg", 5};
  TimezoneInfo res = TimezoneFinder::GetTimezone(56.8380, 60.5974);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Omsk) {
  TimezoneInfo exp = {"Asia/Omsk", 6};
  TimezoneInfo res = TimezoneFinder::GetTimezone(54.9893, 73.3682);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Krasnoyarsk) {
  TimezoneInfo exp = {"Asia/Krasnoyarsk", 7};
  TimezoneInfo res = TimezoneFinder::GetTimezone(56.0153, 92.8932);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Novosibirsk) {
  TimezoneInfo exp = {"Asia/Novosibirsk", 7};
  TimezoneInfo res = TimezoneFinder::GetTimezone(55.0084, 82.9357);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Novokuznetsk) {
  TimezoneInfo exp = {"Asia/Novokuznetsk", 7};
  TimezoneInfo res = TimezoneFinder::GetTimezone(53.7557, 87.1099);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Barnaul) {
  TimezoneInfo exp = {"Asia/Barnaul", 7};
  TimezoneInfo res = TimezoneFinder::GetTimezone(53.3481, 83.7798);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Tomsk) {
  TimezoneInfo exp = {"Asia/Tomsk", 7};
  TimezoneInfo res = TimezoneFinder::GetTimezone(56.5010, 84.9925);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Irkutsk) {
  TimezoneInfo exp = {"Asia/Irkutsk", 8};
  TimezoneInfo res = TimezoneFinder::GetTimezone(52.2870, 104.3050);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Chita) {
  TimezoneInfo exp = {"Asia/Chita", 9};
  TimezoneInfo res = TimezoneFinder::GetTimezone(52.0340, 113.4994);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Yakutsk) {
  TimezoneInfo exp = {"Asia/Yakutsk", 9};
  TimezoneInfo res = TimezoneFinder::GetTimezone(62.0281, 129.7326);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Khandyga) {
  TimezoneInfo exp = {"Asia/Khandyga", 9};
  TimezoneInfo res = TimezoneFinder::GetTimezone(62.6569, 135.5536);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, UstNera) {
  TimezoneInfo exp = {"Asia/Ust-Nera", 10};
  TimezoneInfo res = TimezoneFinder::GetTimezone(64.5667, 143.2000);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Vladivostok) {
  TimezoneInfo exp = {"Asia/Vladivostok", 10};
  TimezoneInfo res = TimezoneFinder::GetTimezone(43.1155, 131.8855);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Magadan) {
  TimezoneInfo exp = {"Asia/Magadan", 11};
  TimezoneInfo res = TimezoneFinder::GetTimezone(59.5615, 150.8006);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Sakhalin) {
  TimezoneInfo exp = {"Asia/Sakhalin", 11};
  TimezoneInfo res = TimezoneFinder::GetTimezone(50.3294, 142.7065);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Srednekolymsk) {
  TimezoneInfo exp = {"Asia/Srednekolymsk", 11};
  TimezoneInfo res = TimezoneFinder::GetTimezone(67.4500, 153.7167);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Anadyr) {
  TimezoneInfo exp = {"Asia/Anadyr", 12};
  TimezoneInfo res = TimezoneFinder::GetTimezone(64.7333, 177.5167);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}

TEST(TimezoneTest, Kamchatka) {
  TimezoneInfo exp = {"Asia/Kamchatka", 12};
  TimezoneInfo res = TimezoneFinder::GetTimezone(53.0452, 158.6518);
  EXPECT_EQ(res.tzId, exp.tzId);
  EXPECT_EQ(res.utcOffset, exp.utcOffset);
}