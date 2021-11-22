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

# install target
install(TARGETS three
        ARCHIVE DESTINATION lib)

# install headers
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/three/
        DESTINATION include/three
        FILES_MATCHING PATTERN "*.h*")
