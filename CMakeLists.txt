cmake_minimum_required(VERSION 3.22)
project(TZFinder)

if (EXISTS "${CMAKE_SOURCE_DIR}/.git")
    execute_process(COMMAND git submodule update --init --recursive WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif ()

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/external/rapidjson/include)

add_executable(TZFinder ./src/main.cc ./src/TimezoneFinder.cc)

enable_testing()

add_subdirectory(external/googletest)

add_executable(tests tests/test_main.cc tests/test_finder.cc src/TimezoneFinder.cc)

target_link_libraries(tests gtest_main)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(tests)
