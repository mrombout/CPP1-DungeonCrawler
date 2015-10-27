//
// Created by Robin de Mug on 27/10/15.
//

#include <util/ServiceLocator.h>
#include <Game.h>
#include <iostream>
#include "RestCommand.h"

namespace dc {
    namespace game {
        RestCommand::RestCommand(dc::model::Player &player) :
                mPlayer(player) {

        }

        void RestCommand::execute() const {
            int healthIncrease = 10;
            if (mPlayer.health() < mPlayer.maxHealth()) {
                int diff = mPlayer.maxHealth() - mPlayer.health();
                if (diff < healthIncrease) {
                    healthIncrease = diff;
                }


                mPlayer.increaseHealth(healthIncrease);
                std::cout << "Resting... Added " << healthIncrease << "HP, your Health right now: " <<
                mPlayer.health() << "HP" << std::endl;
            } else {
                std::cout << "You're already fully rested" << std::endl;
            }
        }

        RestCommand *RestCommand::create(Parameters parameters) {
            return new RestCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player());
        }
    }
}