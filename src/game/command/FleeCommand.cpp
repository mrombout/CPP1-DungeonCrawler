#include <iostream>
#include "util/console.h"
#include "util/ServiceLocator.h"
#include "FleeCommand.h"
#include "GoToCommand.h"
#include "GameLoop.h"
#include "Game.h"
#include "Player.h"

namespace dc {
    namespace game {
        FleeCommand::FleeCommand(GameLoop &gameLoop, model::Player &player, GoToCommand *command) :
                mGameLoop(gameLoop),
                mGoToCommand(command),
                mPlayer(player) {

        }

        FleeCommand::~FleeCommand() {
            delete mGoToCommand;
        }

        void FleeCommand::execute() const {
            if(rand() % 100 > 25) {
                std::cout << csl::color(csl::GREEN) << "You almost tumble over your clumsy feet as you successfully make your desperate escape.";

                dc::model::Room *room = mPlayer.room();
                mGoToCommand->execute();
                mGameLoop.popState();
                room->tickMobs(mPlayer);
            } else {
                std::cout << csl::color(csl::RED) << "You tumble over your clumsy feet as you desperately try to escape. There is no other way that to fight.";
            }

            std::cout << std::endl;
        }

        FleeCommand *FleeCommand::create(Parameters parameters) {
            dc::game::GoToCommand *goToCommand = dc::game::GoToCommand::create(parameters);
            if(!goToCommand)
                return nullptr;

            dc::game::GameLoop &gameLoop = ServiceLocator::getInstance().resolve<dc::game::GameLoop>();
            dc::model::Player &player = ServiceLocator::getInstance().resolve<dc::model::Game>().player();

            return new FleeCommand(gameLoop, player, goToCommand);
        }

        bool FleeCommand::isAction() const {
            return true;
        }
    }
}
