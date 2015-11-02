#include <string>
#include <sstream>
#include <vector>
#include <command/FleeCommand.h>
#include <command/LightRoomCommand.h>
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

            std::vector<dc::model::Mob*> mobs = mGame.player().room()->mobs();
            for(dc::model::Mob* mob : mobs) {
                std::cout << "Setting all mobs to COMBAT" << std::endl;
                mob->setState(dc::model::Mob::State::COMBAT);
            }
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

            if(!Render::prompt(player, gameLoop))
                return "";

            std::string input;

            std::getline(std::cin, input);

            return input;
        }

        dc::game::Command *CombatState::onEval(std::string input) {
            // determine command
            dc::game::Command *command = mCommandManager.create(input);

            return command;
        }

        void CombatState::onPrint(dc::game::GameLoop &gameLoop, dc::game::Command *command) {
            if(!mGame.player().room()->isLighted() && !dynamic_cast<dc::game::FleeCommand*>(command) && !dynamic_cast<dc::game::LightRoomCommand*>(command)) {
                std::cout << "It's too dark to do anything!" << std::endl;
            } else {
                // execute player turn
                command->execute();

                if(!command->isAction())
                    return;
            }

            // execute enemies turn
            dc::model::Game &game = ServiceLocator::getInstance().resolve<dc::model::Game>();
            dc::model::Player &player = game.player();
            dc::model::Room *room = player.room();
            room->tickMobs(player);
        }
    }
}
