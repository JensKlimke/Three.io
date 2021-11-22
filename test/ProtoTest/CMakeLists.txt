# create target
add_executable(ProtoTest ProtoTest.cpp)

# link library
target_link_libraries(ProtoTest PRIVATE proto)

# add test
add_gtest(ProtoTest)