#include <algorithm>

#include "TimeZoneFinder.h"
#include "TimezoneOffsets.h"

TimezoneInfo TimezoneFinder::GetTimezone(float lat, float lon, bool rusOnly) {
  if (lat > 90 || lat < -90 || lon > 180 || lon < -180)
    throw std::runtime_error("Incorrect coordinates range");

  TimezoneInfo res = {"None", 0};
  std::vector<TimezoneRegion> regions = LoadFromFile(rusOnly ? JSON_RUSSIA : JSON_WORLD);
  Point p(lon, lat);

  for (const auto &region: regions) {
    if (!region.bbox.contains(lat, lon)) continue;
    for (const auto &polygon: region.polygons)
      if (IsPointInPolygon(p, polygon)) {
        res.tzId = region.tzId;
        auto it = tzOffsets.find(res.tzId);
        if (it != tzOffsets.end())
          res.utcOffset = it->second.first;
      }
  }
  return res;
}


std::vector<TimezoneRegion> TimezoneFinder::LoadFromFile(const std::string &filepath) {
  std::vector<TimezoneRegion> regions;

  FILE *fp = fopen(filepath.c_str(), "rb");
  if (!fp)
    throw std::runtime_error("Failed to open geojson file: " + filepath);

  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  rapidjson::Document doc;
  doc.ParseStream(is);
  fclose(fp);

  if (!doc.IsObject() || !doc.HasMember("features") || !doc["features"].IsArray())
    throw std::runtime_error("Invalid geojson");

  for (const auto &feature: doc["features"].GetArray()) {
    if (!feature.IsObject()) continue;

    std::string tzId;
    if (feature.HasMember("properties") && feature["properties"].HasMember("tzid"))
      tzId = feature["properties"]["tzid"].GetString();

    const auto &geometry = feature["geometry"];
    std::string geomType = geometry["type"].GetString();

    TimezoneRegion region;
    region.tzId = tzId;

    const auto &coords = geometry["coordinates"];

    if (geomType == "Polygon") {
      for (const auto &ring: coords.GetArray()) {
        std::vector<Point> polygon;
        for (const auto &point: ring.GetArray()) {
          float lon = point[0].GetFloat();
          float lat = point[1].GetFloat();
          polygon.emplace_back(lon, lat);
        }
        region.polygons.push_back(polygon);
      }
    } else if (geomType == "MultiPolygon") {
      for (const auto &polygon: coords.GetArray()) {
        for (const auto &ring: polygon.GetArray()) {
          std::vector<Point> poly;
          for (const auto &point: ring.GetArray()) {
            float lon = point[0].GetFloat();
            float lat = point[1].GetFloat();
            poly.emplace_back(lon, lat);
          }
          region.polygons.push_back(poly);
        }
      }
    }
    region.bbox = ComputeBB(region.polygons);
    regions.push_back(region);
  }
  return regions;
}

BoundingBox TimezoneFinder::ComputeBB(const std::vector<std::vector<Point> > &polygons) {
  BoundingBox bbox = {-90, 90, -180, 180};

  for (const auto &polygon: polygons) {
    for (const auto &point: polygon) {
      float lon = point.first;
      float lat = point.second;
      bbox.minLat = std::min(bbox.minLat, lat);
      bbox.maxLat = std::max(bbox.maxLat, lat);
      bbox.minLon = std::min(bbox.minLon, lon);
      bbox.maxLon = std::max(bbox.maxLon, lon);
    }
  }
  return bbox;
}


bool TimezoneFinder::IsPointInPolygon(const Point &point, const std::vector<Point> &polygon) {
  size_t n = polygon.size();
  int count = 0;

  for (size_t i = 0; i < n; i++) {
    Point p1 = polygon[i];
    Point p2 = polygon[(i + 1) % n];

    if ((point.second > std::min(p1.second, p2.second)) && (point.second <= std::max(p1.second, p2.second)) && (
            point.first <= std::max(p1.first, p2.first))) {
      float xIntersect = (point.second - p1.second) * (p2.first - p1.first) / (p2.second - p1.second) + p1.first;
      if (p1.first == p2.first || point.first <= xIntersect)
        count++;
    }
  }
  return count % 2 == 1;
}
