# create target
add_executable(ProtoTest
        ProtoComplexTest.cpp
        ProtoPointMassTest.cpp
        )

# link library
target_link_libraries(ProtoTest PRIVATE proto)

# add test
add_gtest(ProtoTest)