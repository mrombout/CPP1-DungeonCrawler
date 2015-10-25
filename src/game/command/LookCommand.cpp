#include <iostream>
#include "LookCommand.h"
#include "Mob.h"
#include "util/console.h"

namespace dc {
    game::LookCommand::LookCommand(dc::model::Player &player) :
        mPlayer(player) {

    }

    void game::LookCommand::execute() const {
        dc::model::Room& room = mPlayer.room();

        // name room
        std::cout << csl::color(csl::YELLOW) << room.name() << "\n";

        // describe room
        std::cout << csl::color(csl::WHITE) << mPlayer.room().description();

        // list monsters
        if(!room.mobs().empty()) {
            std::cout << "\n\n" << csl::color(csl::RED) << "In the darkness of the rooms lurk:" << "\n";
            const std::vector<dc::model::Mob*> &mobs = room.mobs();
            for(auto it = mobs.cbegin(); it != mobs.cend(); ++it) {
                int index = std::distance(mobs.cbegin(), it);
                dc::model::Mob* mob = (*it);

                // loop through colors 2 to 8
                std::cout << csl::color(index % 7 + 2) << "[" << index + 1 << "] a " << mob->name() << "(" << mob->health() << "/" << mob->maxHealth() << ")" << "\n";
            }
        }

        std::cout << std::endl;
    }
}