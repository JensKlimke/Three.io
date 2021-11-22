# set source files
set(SOURCE_FILES
        SimpleTest.cpp)

# create target
add_executable(Test ${SOURCE_FILES})

# include directory
target_include_directories(Test PRIVATE
        ${PROJECT_SOURCE_DIR}/src       # for sources
        ${PROJECT_SOURCE_DIR}/include)  # for libraries

# link library to target
target_link_libraries(Test PRIVATE three)

# add gtest libs
add_gtest(Test)

# Note: add_gtest is just a macro that adds gtest, gmock, and gtest_main, and then runs add_test to create a test with the same name:
# target_link_libraries(SimpleTest gtest gmock gtest_main)
# add_test(SimpleTest SimpleTest)