if(BUILD_LIBRARY)
    add_subdirectory(three)
endif()

if(BUILD_PROTOBUF_EXAMPLES)
    add_subdirectory(proto)
endif()

if(BUILD_REPORT_EXAMPLES)
    add_subdirectory(report)
endif()
