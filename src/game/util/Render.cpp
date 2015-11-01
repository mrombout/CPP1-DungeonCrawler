#include <iostream>
#include <GameLoop.h>
#include <state/WelcomeState.h>
#include "util/console.h"
#include "Render.h"

namespace dc {
    namespace game {
        void Render::mobList(const std::vector<dc::model::Mob *> &mobs) {
            for(auto it = mobs.cbegin(); it != mobs.cend(); ++it) {
                int index = std::distance(mobs.cbegin(), it);
                dc::model::Mob* mob = (*it);

                // loop through colors 2 to 8
                std::cout << csl::color(index % 7 + 2) << "[" << index + 1 << "] a " << mob->name() << " (" << mob->health() << "/" << mob->maxHealth() << ")";
                std::cout << " LVL: " << mob->level() << "\n";
            }

            std::cout.flush();
        }

        bool Render::prompt(model::Player &player, dc::game::GameLoop &gameLoop) {
            if(player.isDead()) {
                std::cout << csl::color(csl::LIGHTRED) << "You are dead, you loser." << std::endl;
                while(!dynamic_cast<dc::game::WelcomeState*>(gameLoop.currentState())) {
                    gameLoop.popState();
                }
                return false;
            }

            std::cout << csl::color(csl::GREY) << "HP ";
            std::cout << csl::color(csl::GREEN) << "(";
            if(player.health() < player.maxHealth() / 2) {
                std::cout << csl::color(csl::RED);
            } else {
                std::cout << csl::color(csl::GREEN);
            }
            std::cout << player.health() << csl::color(csl::GREEN) << "/" << player.maxHealth() << ")" << csl::color(csl::GREY);
            std::cout << " Level: " << csl::color(csl::BLUE) << player.level() << csl::color(csl::GREY);
            std::cout << " XP: " << csl::color(csl::MAGENTA) << player.experience() << csl::color(csl::GREY) << " > ";

            return true;
        }
    }
}
