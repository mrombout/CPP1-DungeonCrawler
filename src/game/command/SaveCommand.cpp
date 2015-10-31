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
        SaveCommand::SaveCommand(model::Game &game) :
            mGame(game) {

        }

        void SaveCommand::execute() const {
            std::cout << "Saving to disk... Please do not turn off your console." << std::endl;

            std::string basePath = "sav/" + mGame.player().name();
            FileSystem::mkdir(basePath);

            // save Game
            std::string outputFile = basePath + "/game.txt";
            std::ofstream gos{outputFile};

            gos << mGame;

            // save Player
            outputFile = basePath + "/player.txt";
            std::ofstream pos{outputFile};

            pos << static_cast<dc::model::Character&>(mGame.player());

            // save Inventory
            outputFile = basePath + "/inventory.txt";
            std::ofstream ios{outputFile};

            ios << mGame.player().inventory();

            std::cout << "Done!" << std::endl;
        }

        SaveCommand *SaveCommand::create(Parameters parameters) {
            return new SaveCommand(ServiceLocator::getInstance().resolve<dc::model::Game>());
        }
    }
}