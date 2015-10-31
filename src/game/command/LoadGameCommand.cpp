#include <fstream>
#include <iostream>
#include "LoadGameCommand.h"
#include "util/ServiceLocator.h"
#include "Options.h"
#include "generator/FloorGenerator.h"
#include "generator/DungeonGenerator.h"
#include "item/Iconograph.h"
#include "item/Grenade.h"
#include "item/Talisman.h"
#include "item/HealthPotion.h"
#include "item/Compass.h"
#include "NewGameCommand.h"
#include "GameLoop.h"
#include "state/GameplayState.h"
#include "util/console.h"
#include "util/Number.h"
#include "Player.h"
#include "Dungeon.h"
#include "Game.h"
#include "Floor.h"

namespace dc {
    namespace game {
        LoadGameCommand::LoadGameCommand(dc::game::GameLoop &gameLoop, dc::game::ItemLoader &itemLoader) :
                mGameLoop(gameLoop),
                mItemLoader(itemLoader) {

        }

        void LoadGameCommand::execute() const {
            // ask for name
            std::cout << "Which save do you want to load? ";
            std::string name;
            std::cin >> name;

            std::string basePath{"sav/Mike"};

            // load game.txt
            std::string gamePath{basePath + "/game.txt"};
            std::ifstream gameFile{gamePath};

            int seed;
            gameFile >> seed;

            // generate dungeon from seed
            ServiceLocator &sl = ServiceLocator::getInstance();
            dc::model::Options &options = sl.resolve<dc::model::Options>();
            dc::game::DungeonGenerator *dungeonGenerator = sl.create<dc::game::DungeonGenerator>();

            model::Dungeon* dungeon = dungeonGenerator->generate(seed, options.getInt("dungeon.width"), options.getInt("dungeon.height"));

            // load player.txt
            std::string playerPath{basePath + "/player.txt"};
            std::ifstream playerFile{playerPath};

            model::Player *player = new model::Player();
            playerFile >> *player;

            // read item id
            int itemId;
            playerFile >> itemId;

            if(itemId != -1) {
                dc::model::Item *item = mItemLoader.createItem((unsigned int &) itemId);
                player->setWeapon(dynamic_cast<dc::model::Equipable*>(item));
                player->inventory().add(*item);
            }

            // read position
            Point roomPosition(dungeon->floor(0).startRoom().position());
            int floorLevel;

            playerFile >> roomPosition >> floorLevel;

            std::vector<std::vector<dc::model::Room*>> grid = dungeon->floor(floorLevel - 1).rooms();
            player->setRoom(grid[roomPosition.y()][roomPosition.x()]);

            // add standard items
            model::Item *iconograph = new Iconograph();
            player->inventory().addItem(*iconograph);

            model::Item *grenade = new model::Grenade();
            player->inventory().addItem(*grenade);

            model::Item *talisman = new model::Talisman();
            player->inventory().addItem(*talisman);

            model::HealthPotion *healthPotion = new model::HealthPotion(-1, "Potion", "Test Potion Description", 50);
            player->inventory().addItem(healthPotion);

            model::Item *compass = new model::Compass();
            player->inventory().addItem(*compass);

            dc::model::Game *game = new dc::model::Game(seed, dungeon, player);
            ServiceLocator::getInstance().addInstance<dc::model::Game>(*game);

            mGameLoop.pushState(new GameplayState(game));
        }

        LoadGameCommand *LoadGameCommand::create() {
            ServiceLocator &sl = ServiceLocator::getInstance();
            return new LoadGameCommand(sl.resolve<dc::game::GameLoop>(), sl.resolve<dc::game::ItemLoader>());
        }
    }
}
