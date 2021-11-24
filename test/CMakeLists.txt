if(BUILD_LIBRARY AND BUILD_APP)
    add_subdirectory(application)
endif()

if(BUILD_LIBRARY)
    add_subdirectory(ThreeTest)
endif()

if(BUILD_PROTOBUF_EXAMPLES)
    add_subdirectory(ProtoTest)
endif()

if(BUILD_REPORT_EXAMPLES)
    add_subdirectory(ReportTest)
endif()
