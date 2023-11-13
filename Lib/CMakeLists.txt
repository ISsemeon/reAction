cmake_minimum_required(VERSION 3.14)

project(Lib LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

set(HEADERS "")
set(SOURCES "")

set(HEADERS

)

set(SOURCES

)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE . PUBLIC Include)

# target_link_libraries(ConverterLib PRIVATE Qt${QT_VERSION_MAJOR}::Core libraryName)

target_compile_definitions(Lib PRIVATE CONVERTERLIB_LIBRARY)
