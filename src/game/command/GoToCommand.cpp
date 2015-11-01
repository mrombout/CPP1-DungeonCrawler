#include <iostream>
#include "util/ServiceLocator.h"
#include "Game.h"
#include "Room.h"
#include "Player.h"
#include "GoToCommand.h"
#include "Parameters.h"
#include "Passage.h"
#include "Trap.h"

namespace dc {
    namespace game {
        GoToCommand::GoToCommand(std::string heading, dc::model::Player &player, dc::model::Passage &passage) :
                mHeading(heading),
                mPlayer(player),
                mPassage(passage) {

        }

        void game::GoToCommand::execute() const {
            if(springTraps())
                return;

            dc::model::Room &otherRoom = mPassage.otherSide(*mPlayer.room());
            mPlayer.setRoom(&otherRoom);

            std::cout << "You went " << mHeading << " into the next room." << std::endl;
        }

        bool GoToCommand::springTraps() const {
            const std::vector<dc::model::Trap*> &traps = mPlayer.room()->traps();
            if(!traps.empty()) {
                for(dc::model::Trap *trap : traps) {
                    if(trap->isSprung() || trap->isDismantled())
                        continue;

                    std::cout << "You sprung a " << trap->name() << " trap!" << "\n";
                    trap->spring(mPlayer);
                    return true;
                }
                std::cout << std::endl;
            }

            return false;
        }

        GoToCommand *GoToCommand::create(Parameters parameters) {
            if(parameters.num() != 1) {
                std::cout << "Could not determine the way to go without direction!" << std::endl;
                return nullptr;
            }

            std::string heading = parameters.param(0);

            dc::model::Game &game = ServiceLocator::getInstance().resolve<dc::model::Game>();
            dc::model::Player &player = game.player();

            dc::model::Room *currentRoom = player.room();
            dc::model::Passage *passage = nullptr;

            if (heading == "north") {
                passage = currentRoom->north();
            } else if (heading == "east") {
                passage = currentRoom->east();
            } else if (heading == "south") {
                passage = currentRoom->south();
            } else if (heading == "west") {
                passage = currentRoom->west();
            }

            if(passage == nullptr) {
                std::cout << "Invalid direction, either use north, east, south or west" << std::endl;
                return nullptr;
            }

            return new dc::game::GoToCommand(heading, player, *passage);
        }

        bool GoToCommand::isAction() const {
            return true;
        }
    }
}