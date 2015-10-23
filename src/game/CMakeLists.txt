project(GameLoop)

file(GLOB_RECURSE GAME_SRC ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
file(GLOB_RECURSE GAME_INC ${CMAKE_CURRENT_SOURCE_DIR} *.h)

add_executable(game ${GAME_SRC} ${GAME_INC} command/InventoryCommand.cpp command/InventoryCommand.h command/GoToCommand.cpp command/GoToCommand.h)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Engine_SOURCE_DIR} ${Model_SOURCE_DIR})
target_link_libraries(game model)