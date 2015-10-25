project(Core)

file(GLOB_RECURSE CORE_SRC ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
file(GLOB_RECURSE CORE_INC ${CMAKE_CURRENT_SOURCE_DIR} *.h)

add_library(core ${CORE_SRC} ${CORE_INC})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})