project(Launcher)

file(GLOB_RECURSE LAUNCHER_SRC ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
file(GLOB_RECURSE LAUNCHER_INC ${CMAKE_CURRENT_SOURCE_DIR} *.h)

add_executable(launcher ${LAUNCHER_SRC} ${LAUNCHER_INC})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Engine_SOURCE_DIR} ${Game_SOURCE_DIR})
target_link_libraries(launcher game engine)
message(STATUS )