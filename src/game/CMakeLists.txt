project(Game)

file(GLOB_RECURSE GAME_SRC ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
file(GLOB_RECURSE GAME_INC ${CMAKE_CURRENT_SOURCE_DIR} *.h)

add_executable(game ${GAME_SRC} ${GAME_INC} command/InventoryCommand.cpp command/InventoryCommand.h command/GoToCommand.cpp command/GoToCommand.h command/ClearCommand.cpp command/ClearCommand.h command/RestCommand.cpp command/RestCommand.h command/EquipCommand.cpp command/EquipCommand.h)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Core_SOURCE_DIR} ${Model_SOURCE_DIR})
target_link_libraries(game core model)