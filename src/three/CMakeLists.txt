# set source files
set(SOURCE_FILES
        three.cpp)

# create target
add_library(three STATIC ${SOURCE_FILES})
add_definitions(-DTHREE_EXPORTS)

# include directory
target_include_directories(three PRIVATE
        ${PROJECT_SOURCE_DIR}/include/three # headers for library
        )

# define vars
set(INCLUDE_INSTALL_DIR include/ CACHE STRING "include install dir")
set(LIB_INSTALL_DIR lib/ CACHE STRING "lib install dir")
set(SYSCONFIG_INSTALL_DIR etc/three/ CACHE STRING "sysconfig install dir")

# install target
install(TARGETS three LIBRARY DESTINATION ${LIB_INSTALL_DIR})

# install headers
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/three/
        DESTINATION ${INCLUDE_INSTALL_DIR}three
        FILES_MATCHING PATTERN "*.h*")
