#include <fstream>
#include <iostream>
#include <util/FileSystem.h>
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

            std::string basePath = "sav/" + mPlayer.name();
            FileSystem::mkdir(basePath);

            // save Player
            std::string outputFile = basePath + "/player.txt";
            std::ofstream pos{outputFile};

            pos << static_cast<dc::model::Character&>(mPlayer);

            // save Inventory
            outputFile = basePath + "/inventory.txt";
            std::ofstream ios{outputFile};

            ios << mPlayer.inventory();

            std::cout << "Done!" << std::endl;
        }

        SaveCommand *SaveCommand::create(Parameters parameters) {
            return new SaveCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player());
        }
    }
}