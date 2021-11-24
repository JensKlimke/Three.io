# create target
add_executable(ReportTest ReportTest.cpp)

# link library to target
target_link_libraries(ReportTest PRIVATE report)

# add gtest libs
add_gtest(ReportTest)

# copy configure file to be available in build folder
configure_file(PlotExample.ipynb notebook.ipynb COPYONLY)
