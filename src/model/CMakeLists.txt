project(Model)

file(GLOB_RECURSE MODEL_SRC ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
file(GLOB_RECURSE MODEL_INC ${CMAKE_CURRENT_SOURCE_DIR} *.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Core_SOURCE_DIR})
add_library(model ${MODEL_SRC} ${MODEL_INC})
target_link_libraries(model core)
