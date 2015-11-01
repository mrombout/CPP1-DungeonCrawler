#include <iostream>
#include <item/HealthPotion.h>
#include "Inventory.h"
#include "item/Sword.h"
#include "generator/FloorGenerator.h"
#include "generator/MobGenerator.h"
#include "generator/BSPFloorGenerator.h"
#include "generator/SimpleFloorGenerator.h"
#include "generator/DungeonGenerator.h"
#include "GameplayState.h"
#include "Game.h"
#include "Trap.h"
#include "Player.h"
#include "Dungeon.h"
#include "Options.h"
#include "command/NullCommand.h"
#include "CombatState.h"
#include "item/Iconograph.h"
#include "item/Talisman.h"
#include "item/Grenade.h"
#include "item/Compass.h"
#include "util/ServiceLocator.h"
#include "util/console.h"

namespace dc {
    namespace game {
        GameplayState::GameplayState(dc::model::Game *game) :
            mGame(game),
            mCommandManager() {

        }

        GameplayState::~GameplayState() {
            ServiceLocator::getInstance().removeInstance<dc::model::Game>(*mGame);
            delete mGame;
        }


        void GameplayState::onInitialize(game::GameLoop *game) {

        }

        void GameplayState::onEnter(game::GameLoop *game) {

        }

        std::string GameplayState::onRead() {
            std::cout << csl::color(csl::GREY) << "> ";

            std::string input;

            while(input.empty())
                std::getline(std::cin, input);

            return input;
        }

        game::Command *GameplayState::onEval(std::string input) {
            game::Command *command = mCommandManager.create(input);
            if(!command) {
                std::cout << csl::color(csl::RED) << "Command not recognized" << std::endl;
                // TODO: Cache this NullCommand
                return new NullCommand();
            }

            return command;
        }

        // TODO: Duplicate code in WelcomeState
        void GameplayState::onPrint(game::GameLoop &game, game::Command *command) {
            //game::CommandParameters cp(ServiceLocator::getInstance().resolve<dc::game::GameLoop>(), mGame->player(), *this);
            command->execute();

            updateEnemies(game);
            springTraps(game);
        }

        void GameplayState::updateEnemies(game::GameLoop &game) const {
            std::cout << csl::color(csl::WHITE) << "The enemies scuffle about." << std::endl;
            const std::vector<dc::model::Mob*> &mobs = mGame->player().room()->mobs();
            for(dc::model::Mob *mob : mobs) {
                if(mob->isDead()) {
                    mGame->player().room()->removeMob(mob);
                }
            }

            if(!mobs.empty()) {
                game.pushState(new CombatState(*mGame));
            }
        }

        void GameplayState::springTraps(game::GameLoop &game) {
            const std::vector<dc::model::Trap*> &traps = mGame->player().room()->traps();
            if(!traps.empty()) {
                std::cout << "You hear a sudden click, ever so lightly echo through the room...\n";
                for(dc::model::Trap *trap : traps) {
                    if(trap->isSprung())
                        continue;
                    
                    std::cout << "You sprung a " << trap->name() << " trap!" << "\n";
                    trap->spring(mGame->player());
                }
                std::cout << std::endl;
            }
        }
    }
}