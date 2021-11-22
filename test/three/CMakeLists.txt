# set source files
set(SOURCE_FILES
        ThreeTest.cpp)

# create target
add_executable(ThreeTest ${SOURCE_FILES})

# include directory
target_include_directories(ThreeTest PRIVATE
        ${PROJECT_SOURCE_DIR}/src       # for sources
        ${PROJECT_SOURCE_DIR}/include)  # for libraries

# link library to target
target_link_libraries(ThreeTest PRIVATE three)

# add gtest libs
add_gtest(ThreeTest)