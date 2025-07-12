#include <iostream>
#include <algorithm>
#include "TimezoneFinder.h"

using namespace std;

pair<float, float> parseArgs(int argc, const vector<string> &argv);

int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 5) {
    cerr << "Wrong usage of arguments. Usage: ./TZFinder <latitude> <longitude>";
    return -1;
  }

  vector<string> vArgv(argv, argv + argc);
  auto [lat, lon] = parseArgs(argc, vArgv);
  if (lat == -1000 || lon == -1000)
    return -1;
  try {
    auto [tzId, utcOffset] = TimezoneFinder::GetTimezone(lat, lon);
    cout << tzId << ", " << "UTC" << showpos << utcOffset;
  } catch (const runtime_error &e) {
    cerr << e.what();
  }
  return 0;
}

pair<float, float> parseArgs(int argc, const vector<string> &argv) {
  pair<float, float> res;
  if (argc == 3) {
    try {
      res.first = stof(argv[1]);
      res.second = stof(argv[2]);
    } catch (const invalid_argument &) {
      cerr << "Argument is not a number";
      return {-1000, -1000};
    }
  } else {
    auto latInd = find(begin(argv), end(argv), "--lat");
    auto lonInd = find(argv.begin(), argv.end(), "--lon");

    try {
      res.first = stof(*(latInd + 1));
      res.second = stof(*(lonInd + 1));
    } catch (const invalid_argument &) {
      cerr << "Argument is not a number";
      return {-1000, -1000};
    }
  }
  return res;
}
