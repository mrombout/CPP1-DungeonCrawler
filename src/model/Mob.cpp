#include <util/ServiceLocator.h>
#include <stdlib.h>
#include <iostream>
#include <util/console.h>
#include "Mob.h"
#include "Player.h"
#include "Game.h"

namespace dc {
    namespace model {
        void Mob::kill() {
            mHealth = 0;
        }

        void Mob::damage(unsigned int pDamage) {
            dc::model::Game &game = ServiceLocator::getInstance().resolve<dc::model::Game>();
            dc::model::Player &player = game.player();

            decreaseHealth(pDamage);

            if (!isDead()) {
                player.increaseExperience(level() * 1.5);
                std::cout << csl::color(csl::WHITE) << name() << " is damaged! +" << level() * 1.5 << "XP" << std::endl;

                // Try to attack the player
                std::cout << csl::color(csl::WHITE) << name() << " tries to attack you and, ";
                if(rand() % 100 > 50) {
                    std::cout << csl::color(csl::LIGHTGREEN) << "succeeds!\nYou lose " << attack() << " HP!";
                    player.damage(attack());
                } else {
                    std::cout << csl::color(csl::LIGHTRED) << "misses. Fortunate you!";
                }

                std::cout << "\n" << std::endl;
            } else {
                player.increaseExperience(level() * 3.0);

                std::cout << csl::color(csl::WHITE) << name() << " died! +" << level() * 3.0 << "XP" << std::endl;
                kill();
            }
        };
    }
}
