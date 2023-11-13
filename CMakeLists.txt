cmake_minimum_required(VERSION 3.14)

project(QtApplicationTemplate)

option(ADD_GUI "Build the gui for convertor library" ON)
option(ADD_LIB_EXAMPLES "Build the examples of covertor usage" off)


set (DEST_DIR ${CMAKE_BINARY_DIR}/Bin)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DEST_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DEST_DIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DEST_DIR})

#add_subdirectory(3rdparty/LIBS_NAME)
add_subdirectory(Lib)

if(ADD_GUI)
    add_subdirectory(Gui)
endif()

if(ADD_LIB_EXAMPLES)
    add_subdirectory(Tests)
endif()


