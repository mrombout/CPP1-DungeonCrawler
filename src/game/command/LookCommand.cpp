#include <sstream>
#include <iostream>
#include <iterator>
#include "LookCommand.h"
#include "Game.h"
#include "Room.h"
#include "Player.h"
#include "Trap.h"
#include "item/Item.h"
#include "util/console.h"
#include "util/ServiceLocator.h"
#include "util/Render.h"

namespace dc {
    namespace game {
        LookCommand::LookCommand(model::Player &player) :
                mPlayer(player) {

        }

        void LookCommand::execute() const {
            model::Room *room = mPlayer.room();

            // name room
            std::cout << csl::color(csl::YELLOW) << room->name() << "\n";

            // describe room
            std::cout << csl::color(csl::WHITE) << room->description() << "\n\n";

            // list exits
            std::cout << csl::color(csl::GREY) << "You can go: ";

            std::vector<std::string> exits;
            if(room->north())
                exits.push_back("north");
            if(room->east())
                exits.push_back("east");
            if(room->south())
                exits.push_back("south");
            if(room->west())
                exits.push_back("west");
            std::ostringstream ss;
            std::copy(exits.begin(), exits.end() - 1, std::ostream_iterator<std::string>(ss, ", "));
            ss << exits.back();

            std::cout << ss.str() << "\n";

            // list monsters
            if(!room->mobs().empty()) {
                std::cout << csl::color(csl::RED) << "\n\nIn the darkness of the rooms lurk: \n";
                const std::vector<model::Mob*> &mobs = room->mobs();
                Render::mobList(mobs);
            }

            // list traps
            if(!room->traps().empty()) {
                std::vector<model::Trap*> discoveredTraps;
                for(model::Trap *trap : room->traps()) {
                    if(trap->isDiscovered())
                        discoveredTraps.push_back(trap);
                }

                if(!discoveredTraps.empty()) {
                    std::cout << "\nYou've discovered some traps: \n";
                    for(dc::model::Trap *trap : discoveredTraps) {
                        std::cout << "- " << trap->name() << " (" << (trap->isSprung() || trap->isDismantled() ? "disarmed" : "armed") << ")" << "\n";
                    }
                }
            }

            // items
            if(!room->inventory().items().empty()) {
                std::cout << csl::color(csl::WHITE) << "\nIn the room you see:\n";
                for(model::Item *item : room->inventory().items()) {
                    std::cout << "- a " << item->name() << "\n";
                    std::cout << "\t" << csl::color(csl::DARKGREY) << item->description() << "\n";
                }
            }

            std::cout << std::endl;
        }

        LookCommand *LookCommand::create(Parameters parameters) {
            return new game::LookCommand(ServiceLocator::getInstance().resolve<model::Game>().player());
        }

        bool LookCommand::isAction() const {
            return false;
        }
    }
}