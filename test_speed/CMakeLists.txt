cmake_minimum_required (VERSION 2.8)
project (TEST)

if(CMAKE_CONFIGURATION_TYPES)
   set(CMAKE_CONFIGURATION_TYPES Debug Release)
   set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
     "Reset the configurations to what we need"
     FORCE)
endif()

set(CMAKE_CXX_FLAGS "-Wall -O3 -std=c++11")

set(EXECUTABLE_OUTPUT_PATH ..)
set(LIBRARY_OUTPUT_PATH ..)

include_directories (
..
)

add_executable(tst main.cpp noise.cpp)
target_link_libraries(tst)





