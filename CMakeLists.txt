cmake_minimum_required(VERSION 3.6)
project(cpp-russia-2017)

add_executable(navigation
  src/navigation.cpp
  src/navigation/abrahams_dimov.h
  src/navigation/usings.h
  src/navigation/adl.h
)

find_package(Boost COMPONENTS log REQUIRED)

add_executable(funny-geom
  src/funny-geom.cpp
)

target_include_directories(funny-geom PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

add_executable(arithmetic
  src/ct-arithmetic.cpp
)

target_include_directories(arithmetic PRIVATE ${Boost_INCLUDE_DIRS})

add_executable(intrusive-ptr
  src/intrusive-ptr.cpp
  src/intrusive-ptr.h
)

target_include_directories(intrusive-ptr PRIVATE ${Boost_INCLUDE_DIRS})

add_library(analysis
  src/analysis/inheritance.cpp
  src/analysis/control-flow.cpp
)
