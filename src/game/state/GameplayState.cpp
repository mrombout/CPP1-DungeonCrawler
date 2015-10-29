#include <iostream>
#include "Inventory.h"
#include "Sword.h"
#include "generator/MobGenerator.h"
#include "generator/BSPFloorGenerator.h"
#include "generator/SimpleFloorGenerator.h"
#include "generator/DungeonGenerator.h"
#include "GameplayState.h"
#include "Game.h"
#include "Trap.h"
#include "Player.h"
#include "Dungeon.h"
#include "command/NullCommand.h"
#include "CombatState.h"
#include "item/Iconograph.h"
#include "item/Talisman.h"
#include "item/Grenade.h"
#include "util/ServiceLocator.h"
#include "util/console.h"
#include <vector>

namespace dc {
    namespace game {
        GameplayState::GameplayState() :
            mCommandManager() {

        }

        GameplayState::~GameplayState() {
            ServiceLocator::getInstance().removeInstance<dc::model::Game>(*mGame);
            delete mGame;
        }


        void GameplayState::onInitialize(game::GameLoop *game) {
            // generate random dungeon
            unsigned int seed = 1;

            MobGenerator mobGenerator;
            RoomGenerator roomGenerator(mobGenerator);
            BSPFloorGenerator bspFloorGenerator = BSPFloorGenerator(roomGenerator);
            SimpleFloorGenerator floorGenerator = SimpleFloorGenerator(roomGenerator);
            DungeonGenerator dungeonGenerator(bspFloorGenerator);
            model::Dungeon* dungeon = dungeonGenerator.generate(seed);

            model::Player *player = new model::Player(&dungeon->floor(0).exitRoom());

			// Begin vullen van de inventory

			std::vector<std::string> inventory = FileLoader::getInstance()->getInventory();

			for (std::string item : inventory)
			{
				if (item == "SWORD"){
					player->inventory().addItem(*new model::Sword("Sword", "A Sword"));
				}
				else if (item == "ICONOGRAPH") {
					player->inventory().addItem(*new Iconograph());
				}
				else if (item == "GRENADE"){
					player->inventory().addItem(*new model::Grenade());
				}
				else if (item == "TALISMAN"){
					player->inventory().addItem(*new model::Talisman());
				}
				else {
					std::cout << "Sorry, we can't recognize the " + item + "." << std::endl;
				}
			}

			// Item gebruiken kan dus nu op de volgende manier:
            player->inventory().findItem("TALISMAN")->use(*player);

			// Einde vullen van de inventory

            mGame = new model::Game(dungeon, player);
            ServiceLocator::getInstance().addInstance<dc::model::Game>(*mGame);
        }

        void GameplayState::onEnter(game::GameLoop *game) {

        }

        std::string GameplayState::onRead() {
            std::cout << csl::color(csl::GREY) << "> ";

            std::string input;

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