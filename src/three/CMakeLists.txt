# set source files
set(SOURCE_FILES
        three.cpp)

# create target
add_library(three STATIC ${SOURCE_FILES})
add_definitions(-DTHREE_EXPORTS)

# install target
install(TARGETS three
        ARCHIVE DESTINATION lib)

# install headers
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/three/
        DESTINATION include/three
        FILES_MATCHING PATTERN "*.h*")
