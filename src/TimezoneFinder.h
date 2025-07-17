#ifndef TIMEZONEFINDER_H
#define TIMEZONEFINDER_H

#include <string>
#include <vector>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

#define JSON_WORLD "../data/combined-with-oceans.json"
#define JSON_RUSSIA "../data/russia-timezones.json"

typedef struct {
  std::string tzId;
  float utcOffset;
} TimezoneInfo;

using Point = std::pair<float, float>;

typedef struct {
  float minLat, maxLat;
  float minLon, maxLon;

  bool contains(float lat, float lon) const {
    return lat >= minLat && lat <= maxLat && lon >= minLon && lon <= maxLon;
  }
} BoundingBox;


typedef struct {
  std::string tzId;
  std::vector<std::vector<Point> > polygons;
  BoundingBox bbox;
} TimezoneRegion;

class TimezoneFinder {
public:
  static TimezoneInfo GetTimezone(float lat, float lon, bool rusOnly = true);

private:
  static std::vector<TimezoneRegion> LoadFromFile(const std::string &filepath);

  static bool IsPointInPolygon(const Point &point, const std::vector<Point> &polygon);

  static BoundingBox ComputeBB(const std::vector<std::vector<Point> > &polygons);
};


#endif //TIMEZONEFINDER_H
