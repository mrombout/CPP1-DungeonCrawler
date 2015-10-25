#include <sstream>
#include <iostream>
#include <iterator>
#include "LookCommand.h"
#include "Game.h"
#include "Mob.h"
#include "Room.h"
#include "Player.h"
#include "util/console.h"
#include "util/ServiceLocator.h"

namespace dc {
    game::LookCommand::LookCommand(dc::model::Player &player) :
        mPlayer(player) {

    }

    void game::LookCommand::execute() const {
        dc::model::Room& room = mPlayer.room();

        // name room
        std::cout << csl::color(csl::YELLOW) << room.name() << "\n";

        // describe room
        std::cout << csl::color(csl::WHITE) << mPlayer.room().description() << "\n";

        // list exits
        std::cout << "You can go: ";

        std::vector<std::string> exits;
        if(room.north())
            exits.push_back("north");
        if(room.east())
            exits.push_back("east");
        if(room.south())
            exits.push_back("south");
        if(room.west())
            exits.push_back("west");
        std::ostringstream ss;
        std::copy(exits.begin(), exits.end() - 1, std::ostream_iterator<std::string>(ss, ", "));
        ss << exits.back();

        std::cout << ss.str() << "\n";

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

    dc::game::LookCommand *game::LookCommand::create(Parameters parameters) {
        return new dc::game::LookCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player());
    }
}