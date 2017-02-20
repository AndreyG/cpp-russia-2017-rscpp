cmake_minimum_required(VERSION 3.6)
project(cpp-russia-2017)

add_executable(funny-geom
  src/funny-geom.cpp
)

target_include_directories(funny-geom PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)
