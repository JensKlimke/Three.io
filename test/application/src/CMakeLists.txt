# set source files
set(SOURCE_FILES
        main.cpp)

# create target
add_executable(app ${SOURCE_FILES})

# link library to target
target_link_libraries(app PRIVATE three)