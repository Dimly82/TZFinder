cmake_minimum_required(VERSION 3.22)
project(TZFinder)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/external/rapidjson/include)

add_executable(TZFinder ./src/main.cc ./src/TimeZoneFinder.h ./src/TimeZoneFinder.cc
        src/TimezoneOffsets.h)
