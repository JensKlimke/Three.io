# create target
add_executable(ThreeTest ThreeTest.cpp)

# link library to target
target_link_libraries(ThreeTest PRIVATE three)

# add gtest libs
add_gtest(ThreeTest)