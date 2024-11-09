#Minimum CMake version
cmake_minimum_required(VERSION 3.10)

project(magnets)

set(CMAKE_CXX_STANDARD 23) 
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR} include)

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
