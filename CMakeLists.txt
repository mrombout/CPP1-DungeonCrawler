cmake_minimum_required(VERSION 3.3)

# configure cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# root project
project("DungeonCrawler" CXX)

# include projects
add_subdirectory(src/core)
add_subdirectory(src/model)
add_subdirectory(src/game)

