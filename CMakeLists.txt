cmake_minimum_required(VERSION 3.17)

project(Game_of_Life)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")

#set(SOURCE_FILES game_of_life.cpp Grid.cpp graphic.cpp text.cpp)
set(SOURCE_FILES game_of_life.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(Curses)
include_directories(${CURSES_INCLUDE_DIR})

add_library(libs STATIC Grid.cpp graphic.cpp text.cpp)
target_include_directories(libs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(app ${SOURCE_FILES})

#target_link_libraries(libs PUBLIC libs)
target_link_libraries(app PRIVATE libs SDL2 ${CURSES_LIBRARY})