#include <iostream>
#include "AttackCommand.h"
#include "Game.h"
#include "Equipable.h"
#include "Mob.h"
#include "Player.h"
#include "Room.h"
#include "util/Number.h"
#include "util/console.h"
#include "util/ServiceLocator.h"


namespace dc {
    namespace game {
        AttackCommand::AttackCommand(dc::model::Player &player, dc::model::Mob &mob) :
                mPlayer(player),
                mMob(mob) {

        }

        void AttackCommand::execute() const {
            dc::model::Equipable *weapon = &mPlayer.weapon();
            if (weapon == nullptr) {
                std::cout << "Well, that's a bummer, you haven't equipped a weapon yet!" << std::endl;
            } else {
                std::cout << csl::color(csl::WHITE) << "You attack the " << mMob.name() << " and, ";

                // Reduction bonus (increases chance of a hit) based on player attack level
                double reductionFactor = 0.1 * mPlayer.attack();
                if (rand() % 100 > (50 - reductionFactor)) {
                    int damage = mPlayer.weapon().damage();
                    std::cout << csl::color(csl::LIGHTGREEN) << "hit.\nYou do " << damage << " damage!";

                    mMob.damage(damage);
                } else {
                    std::cout << csl::color(csl::LIGHTRED) << "miss.";
                }
            }

            std::cout << "\n" << std::endl;
        }

        AttackCommand *AttackCommand::create(Parameters parameters) {
            if(parameters.num() != 1) {
                std::cout << "You swing aimlessly...\n" << "Maybe you should target one enemy at a time?" << std::endl;
                return nullptr;
            }

            int monsterNum = (int) Number::toLong(parameters.param(0)) - 1;
            if(monsterNum < 0) {
                std::cout << "You think to yourself, '" << parameters.param(0) << "? That's not a number!'." << std::endl;
                return nullptr;
            }

            dc::model::Player &player = ServiceLocator::getInstance().resolve<dc::model::Game>().player();
            std::vector<dc::model::Mob*> mobs = player.room()->mobs();

            if(monsterNum > mobs.size()) {
                std::cout << "There not even " << monsterNum << "in this room!" << std::endl;
                return nullptr;
            }

            dc::model::Mob* mob = mobs[monsterNum];

            return new AttackCommand(player, *mob);
        }
    }
}
