#include <iostream>
#include "LookCommand.h"
#include "Mob.h"

namespace dc {
    void game::LookCommand::execute(engine::CommandParameters &parameters) const {
        dc::model::Room& room = parameters.player().room();

        // describe room
        std::cout << parameters.player().room().description() << "\n\n";

        // list monsters
        if(!room.mobs().empty()) {
            std::cout << "In the darkness of the rooms lurk:" << "\n";
            for(dc::model::Mob *mob : room.mobs()) {
                std::cout << "- a " << mob->name() << "(" << mob->health() << "/" << mob->maxHealth() << ")" << "\n";
            }
        }
    }
}