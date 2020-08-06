cmake_minimum_required(VERSION 3.5)
project(hungarian CXX)

set(CMAKE_CXX_STANDARD 11 CACHE STRING "C++ standard version to use (default is 11)")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(hungarian Hungarian.cpp)

include(CTest)
if(BUILD_TESTING)
  add_executable(test_hungarian testMain.cpp)
  target_link_libraries(test_hungarian PRIVATE hungarian)
endif()
