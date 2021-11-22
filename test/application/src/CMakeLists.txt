# set source files
set(SOURCE_FILES
        main.cpp)

# create target
add_executable(runnable ${SOURCE_FILES})

# link library to target
target_link_libraries(runnable PRIVATE three)