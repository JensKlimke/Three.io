# create target
add_executable(ReportTest ReportTest.cpp)

# link library to target
target_link_libraries(ReportTest PRIVATE report)

# add gtest libs
add_gtest(ReportTest)

# define file
set(NOTEBOOK_FILE
        PlotExample.ipynb
        )

# copy configure file to be available in build folder
configure_file(${NOTEBOOK_FILE} notebook.ipynb COPYONLY)

# create target to generate html from jupyter notebook
add_custom_target(convert_jnb
        COMMAND jupyter nbconvert --execute --to html notebook.ipynb
        COMMENT "Generate an html artifact from the jupyter notebook"
        SOURCES ${NOTEBOOK_FILE})