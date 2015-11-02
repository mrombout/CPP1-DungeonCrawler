#include <iostream>
#include <stdlib.h>
#include "util/ServiceLocator.h"
#include "util/console.h"
#include "Mob.h"
#include "Player.h"
#include "Game.h"

namespace dc {
    namespace model {
        Mob::Mob(unsigned int id) :
            mId(id),
            mState(Mob::State::IDLE) {

        }

        void Mob::kill() {
            mHealth = 0;
        }

        void Mob::damage(unsigned int pDamage) {
            dc::model::Game &game = ServiceLocator::getInstance().resolve<dc::model::Game>();
            dc::model::Player &player = game.player();

            decreaseHealth(pDamage);

            if (!isDead()) {
                player.increaseExperience(level() * 1.5);
                std::cout << csl::color(csl::WHITE) << " " << name() << " is damaged! +" << level() * 1.5 << "XP" << std::endl;
            } else {
                player.increaseExperience(level() * 3.0);

                std::cout << csl::color(csl::WHITE) << name() << " died! +" << level() * 3.0 << "XP" << std::endl;
                kill();
            }
        };

        std::ostream &operator<<(std::ostream &output, const dc::model::Mob &m) {
            output << std::fixed << std::setprecision(15) << m.mId << "\t" << m.mLevel << "\t" << m.mHealth;

            return output;
        }

        std::istream &operator>>(std::istream &input, dc::model::Mob &m) {
            return input;
        }

        void Mob::tick(dc::model::Character &character) {
            if(mState == COMBAT) {
                // is the player here?
                if(character.room() == this->room()) {
                    // try to attack the player
                    std::cout << csl::color(csl::WHITE) << name() << " tries to attack you and, ";
                    if(rand() % 100 > 50) {
                        std::cout << csl::color(csl::LIGHTGREEN) << "succeeds!\nYou lose " << attack() << " HP!";
                        character.damage(attack());
                    } else {
                        std::cout << csl::color(csl::LIGHTRED) << "misses.";
                    }
                    std::cout << std::endl;
                } else {
                    // follow the player :)
                    room()->removeMob(this);
                    character.room()->addMob(this);
                    std::cout << csl::color(csl::RED) << "The " << name() << " followed you into the room." << std::endl;
                }
            }
        }

        void Mob::setState(Mob::State state) {
            mState = state;
        }
    }
}
