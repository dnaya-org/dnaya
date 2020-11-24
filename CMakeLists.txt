cmake_minimum_required(VERSION 3.17)
project(DNAYA VERSION 0.1.0)

configure_file("include/dnaya/version.hpp.in" "include/dnaya/version.hpp")

add_library(dnaya INTERFACE)

target_compile_features(dnaya INTERFACE cxx_std_20)

target_include_directories(dnaya INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/>)
target_include_directories(dnaya SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>)

option(DNAYA_BUILD_TEST "whether or not to build the test" OFF)
if(DNAYA_BUILD_TEST)
  enable_testing()
  add_subdirectory(test)
endif()

option(DNAYA_BUILD_TOOLS "whether or not to build the tools " OFF)
if(DNAYA_BUILD_TOOLS)
  add_subdirectory(tools)
endif()
