#ifndef TIMEZONEFINDER_H
#define TIMEZONEFINDER_H

#include <string>
#include <vector>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

typedef struct {
  std::string tzId;
  int utcOffset;
} TimezoneInfo;

using Point = std::pair<float, float>;

typedef struct {
  std::string tzId;
  std::vector<std::vector<Point> > polygons;
} TimezoneRegion;

class TimezoneFinder {
public:
  static TimezoneInfo GetTimezone(float lat, float lon);

public:
  static std::vector<TimezoneRegion> LoadFromFile(const std::string &filepath);

  static bool IsPointInPolygon(const Point &point, const std::vector<Point> &polygon);
};


#endif //TIMEZONEFINDER_H
