#include <iostream>
#include "TimezoneFinder.h"

using namespace std;

int main() {
  auto res = TimezoneFinder::GetTimezone(55.7558, 37.6176);
  cout << res.tzId;
  return 0;
}
