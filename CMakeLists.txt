cmake_minimum_required(VERSION 3.5)

# set project title
project(Three.io VERSION 0.1.1)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)

# set options
option(BUILD_TESTING "Sets or unsets the option to generate the test target." OFF)
option(ENABLE_COVERAGE "Enable the coverage check of the module." OFF)
option(BUILD_APP "Enables the example app (integrating the library) to be build." OFF)
option(BUILD_LIBRARY "Enable the library to be build." ON)
option(BUILD_PROTOBUF_EXAMPLES "The protobuf examples and tests are build when activated." ON)
option(BUILD_REPORT_EXAMPLES "Enable the report feature." ON)

# include directory
include_directories(include)

# add ./cmake to CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# load modules
include(ModuleCoverage)
include(ModuleTesting)

# default install dirs
include(GNUInstallDirs)

# ------------------------------------------------------------------------------
# core sources
# - test folder is loaded automatically when BUILD_TESTING is enables
# ------------------------------------------------------------------------------

# add sources
add_subdirectory(src)

