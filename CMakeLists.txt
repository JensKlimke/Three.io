cmake_minimum_required(VERSION 3.5)

# set project title
project(Three.io VERSION 0.1.1)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)

# set options
option(BUILD_TESTING "Sets or unsets the option to generate the test target" OFF)
option(ENABLE_COVERAGE "Enable the coverage check of the module" OFF)
option(BUILD_APP "Enable the app to be build" OFF)

# add ./cmake to CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# load modules
include(ModuleCoverage)
include(ModuleTesting)

# default install dirs
include(GNUInstallDirs)

# ------------------------------------------------------------------------------
# core sources
# ------------------------------------------------------------------------------

# add sources
add_subdirectory(src)

if(${BUILD_APP})

    include_directories(${CMAKE_SOURCE_DIR}/include)
    add_subdirectory(test/application)

endif()
