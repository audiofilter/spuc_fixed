cmake_minimum_required (VERSION 2.8)
project (TEST_INTS)

if(CMAKE_CONFIGURATION_TYPES)
   set(CMAKE_CONFIGURATION_TYPES Debug Release)
   set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
     "Reset the configurations to what we need"
     FORCE)
endif()

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang") 
message(STATUS "Using Clang")
set(CMAKE_CXX_FLAGS "-Werror -std=c++11")
else()
execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                OUTPUT_VARIABLE GCC_VERSION)
if (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
        message(STATUS "GCC Version >=  4.7 => using c++0x compile switch")
		set(CMAKE_CXX_FLAGS "-Werror -std=c++0x -D__STDC_UTF_16__")
		set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++ ")
else()
        message(STATUS "GCC Version < 4.7")
		set(CMAKE_CXX_FLAGS "-Werror")
endif()
endif()

set(EXECUTABLE_OUTPUT_PATH ..)
set(LIBRARY_OUTPUT_PATH ..)



include_directories (
..
)

add_executable(tb_spuc_fixed tb_spuc_fixed.cpp)
add_executable(tb_spuc_fixed_types tb_spuc_fixed_types.cpp)

