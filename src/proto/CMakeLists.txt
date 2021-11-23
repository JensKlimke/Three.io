# find protobuf
find_package(Protobuf REQUIRED)

# generate proto files
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS
        Complex.proto
        PointMass.proto
        )

# create target
add_library(proto STATIC
        MyComplex.cpp
        MyPointMass.cpp
        ${PROTO_SRCS} ${PROTO_HDRS}
        )

target_include_directories(proto PUBLIC
        ${Protobuf_INCLUDE_DIRS}
        ${CMAKE_CURRENT_BINARY_DIR}
        )

message(STATUS ${CMAKE_CURRENT_BINARY_DIR})

# link libraries
target_link_libraries(proto PRIVATE
        ${Protobuf_LIBRARIES}
        )