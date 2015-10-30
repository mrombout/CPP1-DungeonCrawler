#include <string>
#include <sstream>
#include <vector>
#include "Player.h"
#include "Mob.h"
#include "command/AttackCommand.h"
#include "command/InventoryCommand.h"
#include "command/LookCommand.h"
#include "GameplayState.h"
#include "CombatState.h"
#include "util/console.h"
#include "util/ServiceLocator.h"
#include "util/Render.h"

namespace dc {
    namespace game {
        CombatState::CombatState(dc::model::Game &game) :
                mCommandManager(*this),
                mGame(game) {

        }

        CombatState::~CombatState() {

        }

        void CombatState::onInitialize(dc::game::GameLoop *game) {

        }

        void CombatState::onEnter(dc::game::GameLoop *game) {
            std::cout << csl::color(csl::LIGHTRED) << "\nA group of enemies storm towards you." << csl::color(csl::GREY) << "\nYou prepare for battle." << std::endl;
        }

        std::string CombatState::onRead() {
            std::cout << csl::color(csl::RED) << "You are in combat!\n\n" << csl::color(csl::WHITE) << "In front of you stand:" << std::endl;

            dc::game::GameLoop &gameLoop = ServiceLocator::getInstance().resolve<dc::game::GameLoop>();
            dc::model::Game &game = ServiceLocator::getInstance().resolve<dc::model::Game>();
            dc::model::Player &player = game.player();
            std::vector<dc::model::Mob*> mobs = player.room()->mobs();
            if(mobs.empty()) {
                std::cout << "Victorious!" << std::endl;
                gameLoop.popState();
                return "";
            }

            Render::mobList(player.room()->mobs());
            std::cout << "\n";

            int health = player.health();
            unsigned int maxHealth = player.maxHealth();

            if(player.isDead()) {
                std::cout << csl::color(csl::LIGHTRED) << "You are dead, you loser." << std::endl;
                gameLoop.popState();
                gameLoop.popState();
                return "";
            }

            std::cout << csl::color(csl::GREEN) << "(";
            if(health < maxHealth / 2) {
                std::cout << csl::color(csl::RED);
            } else {
                std::cout << csl::color(csl::GREEN);
            }
            std::cout << player.health() << csl::color(csl::GREEN) << "/" << player.maxHealth() << ")" << csl::color(csl::GREY) << ">";

            std::string input;

            std::getline(std::cin, input);

            return input;
        }

        dc::game::Command *CombatState::onEval(std::string input) {
            // determine command
            dc::game::Command *command = mCommandManager.create(input);

            return command;
        }

        void CombatState::onPrint(dc::game::GameLoop &game, dc::game::Command *command) {
            // execute player turn
            command->execute();

            // execute enemies turn
            dc::model::Room *room = ServiceLocator::getInstance().resolve<dc::model::Game>().player().room();
            std::vector<dc::model::Mob*> mobs = room->mobs();
            for(dc::model::Mob* mob : mobs) {
                if(mob->isDead())
                    room->removeMob(mob);
            }
        }
    }
}
