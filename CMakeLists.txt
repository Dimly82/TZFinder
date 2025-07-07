cmake_minimum_required(VERSION 3.22)
project(TZFinder)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/external/rapidjson/include)

add_executable(TZFinder main.cc TimeZoneFinder.h TimeZoneFinder.cc)
