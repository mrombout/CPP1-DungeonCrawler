#include <iostream>
#include "StatsCommand.h"
#include "Game.h"
#include "Player.h"
#include "util/ServiceLocator.h"

namespace dc {
    namespace game {
        StatsCommand::StatsCommand(dc::model::Player &player) :
                mPlayer(player) {

        }

        void StatsCommand::execute() const {
            std::cout << "You reflect on what you have learned: \n\n";

            std::cout << "Level: " << mPlayer.level() << "\n";
            std::cout << "Experience: " << mPlayer.experience() << "\n\n";
            std::cout << "----------------\n\n";
            std::cout << "Health: " << mPlayer.health() << "/" << mPlayer.maxHealth() << "\n";
            std::cout << "Mana: " << mPlayer.mana() << "\n";
            std::cout << "Attack: " << mPlayer.attack() << "\n";
            std::cout << "Defence: " << mPlayer.defence() << "\n";
            std::cout << "Perception: " << mPlayer.perception() << "\n\n" << std::endl;
        }

        StatsCommand *StatsCommand::create(Parameters parameters) {
            return new StatsCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player());
        }

        bool StatsCommand::isAction() const {
            return false;
        }
    }
}
