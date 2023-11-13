cmake_minimum_required(VERSION 3.14)

project(Examples LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Example1 example1.cpp)
target_link_libraries(Example1 PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Example1 PRIVATE ConverterLib)

add_executable(Example2 example2.cpp)
target_link_libraries(Example2 PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Example2 PRIVATE ConverterLib)
