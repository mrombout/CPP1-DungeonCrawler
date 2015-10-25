#include <iostream>
#include "LookCommand.h"
#include "Mob.h"
#include "util/console.h"

namespace dc {
    void game::LookCommand::execute(engine::CommandParameters &parameters) const {
        dc::model::Room& room = parameters.player().room();

        // name room
        std::cout << csl::color(csl::YELLOW) << /*room.name()*/"name" << "\n";

        // describe room
        std::cout << csl::color(csl::WHITE) << /*parameters.player().room().description()*/"desc";

        // list monsters
        if(!room.mobs().empty()) {
            std::cout << "\n\n" << csl::color(csl::RED) << /*"In the darkness of the rooms lurk:"*/"d" << "\n";
            for(dc::model::Mob *mob : room.mobs()) {
                std::cout << "- a " << mob->name() << "(" << mob->health() << "/" << mob->maxHealth() << ")" << "\n";
            }
        }

        std::cout << std::endl;
    }
}