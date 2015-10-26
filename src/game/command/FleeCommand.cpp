#include <iostream>
#include <util/console.h>
#include <util/ServiceLocator.h>
#include "FleeCommand.h"
#include "GoToCommand.h"
#include "GameLoop.h"

namespace dc {
    namespace game {
        FleeCommand::FleeCommand(dc::engine::GameLoop &gameLoop, dc::game::GoToCommand *command) :
                mGameLoop(gameLoop),
                mGoToCommand(command) {

        }

        FleeCommand::~FleeCommand() {
            delete mGoToCommand;
        }

        void FleeCommand::execute() const {
            if(rand() % 100 > 25) {
                std::cout << csl::color(csl::GREEN) << "You almost tumble over your clumsy feet as you successfully make your desperate escape.";
                mGoToCommand->execute();
                mGameLoop.popState();
            } else {
                std::cout << csl::color(csl::RED) << "You tumble over your clumsy feet as you desperately try to escape. There is no other way that to fight.";
            }

            std::cout << std::endl;
        }

        FleeCommand *FleeCommand::create(Parameters parameters) {
            dc::game::GoToCommand *goToCommand = dc::game::GoToCommand::create(parameters);
            if(!goToCommand)
                return nullptr;

            dc::engine::GameLoop &gameLoop = ServiceLocator::getInstance().resolve<dc::engine::GameLoop>();

            return new FleeCommand(gameLoop, goToCommand);
        }

    }
}
