#include <fstream>
#include <iostream>
#include "util/ServiceLocator.h"
#include "Game.h"
#include "Player.h"
#include "Character.h"
#include "SaveCommand.h"

namespace dc {
    namespace game {
        SaveCommand::SaveCommand(model::Player &player) :
            mPlayer(player) {

        }

        void SaveCommand::execute() const {
            std::cout << "Saving to disk... Please do not turn off your console." << std::endl;

            // save Player
            std::string outputFile = "sav/1/player.txt";
            std::ofstream pos{outputFile};

            pos << static_cast<dc::model::Character&>(mPlayer);

            // save Inventory
            outputFile = "sav/1/inventory.txt";
            std::ofstream ios{outputFile};

            ios << mPlayer.inventory();

            std::cout << "Done!" << std::endl;
        }

        SaveCommand *SaveCommand::create(Parameters parameters) {
            return new SaveCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player());
        }
    }
}