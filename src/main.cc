#include <iostream>
#include <algorithm>
#include "TimezoneFinder.h"

using namespace std;

pair<float, float> parseArgs(int argc, const vector<string> &argv);

int main(int argc, char *argv[]) {
  if (argc < 3 || argc > 6) {
    cerr << "Wrong usage of arguments. Usage: ./TZFinder <latitude> <longitude> [--world]";
    return -1;
  }

  vector<string> vArgv(argv, argv + argc);
  bool rusOnly = find(vArgv.begin(), vArgv.end(), "--world") == vArgv.end();
  auto [lat, lon] = parseArgs(argc, vArgv);
  if (lat == -1000 || lon == -1000)
    return -1;
  try {
    auto [tzId, utcOffset] = TimezoneFinder::GetTimezone(lat, lon, rusOnly);
    cout << tzId << ", " << "UTC" << showpos << utcOffset;
  } catch (const runtime_error &e) {
    cerr << e.what();
  }
  return 0;
}

pair<float, float> parseArgs(int argc, const vector<string> &argv) {
  pair<float, float> res = {-1000, -1000};
  if (argc == 3) {
    try {
      res.first = stof(argv[1]);
      res.second = stof(argv[2]);
    } catch (const exception &e) {
      cerr << e.what();
      return {-1000, -1000};
    }
  } else {
    auto latInd = find(begin(argv), end(argv), "--lat");
    auto lonInd = find(argv.begin(), argv.end(), "--lon");

    try {
      res.first = stof(*(latInd + 1));
      res.second = stof(*(lonInd + 1));
    } catch (const exception &e) {
      cerr << e.what();
      return {-1000, -1000};
    }
  }
  return res;
}
