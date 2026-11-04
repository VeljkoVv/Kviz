cmake_minimum_required(VERSION 3.20)
project(Kviz C CXX)
set(CMAKE_CXX_STANDARD 20)

add_library(kviz_lib src/baza.cpp src/igra.cpp src/kviz.cpp src/pitanje.cpp lib/sqlite/sqlite3.c)

add_executable(kviz src/main.cpp)
target_link_libraries(kviz kviz_lib)

enable_testing()
find_package(GTest REQUIRED)
add_executable(testovi tests/pitanje_test.cpp tests/igra_test.cpp tests/baza_test.cpp)
target_link_libraries(testovi kviz_lib GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(testovi WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})