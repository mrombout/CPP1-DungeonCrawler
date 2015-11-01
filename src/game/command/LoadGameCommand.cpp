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
#include "Trap.h"

namespace dc {
    namespace game {
        LoadGameCommand::LoadGameCommand(dc::game::GameLoop &gameLoop, dc::game::ItemLoader &itemLoader, dc::game::TrapLoader &trapLoader, dc::game::MobGenerator &mobGenerator) :
                mGameLoop(gameLoop),
                mItemLoader(itemLoader),
                mTrapLoader(trapLoader),
                mMobGenerator(mobGenerator) {

        }

        void LoadGameCommand::execute() const {
            // ask for name
            std::cout << csl::color(csl::GREY) << "Which save do you want to load? ";
            std::string name;
            std::cin >> name;

            std::string basePath{"sav/" + name};

            // load game.txt
            std::string gamePath{basePath + "/game.txt"};
            std::ifstream gameFile{gamePath};
            if(!gameFile.is_open()) {
                std::cout << "Sorry, that save game is not recognized.\n" << std::endl;
                return;
            }

            int seed;
            gameFile >> seed;

            // generate dungeon from seed
            ServiceLocator &sl = ServiceLocator::getInstance();
            dc::model::Options &options = sl.resolve<dc::model::Options>();
            dc::game::DungeonGenerator *dungeonGenerator = sl.create<dc::game::DungeonGenerator>();

            model::Dungeon* dungeon = dungeonGenerator->generate(seed, options.getInt("dungeon.width"), options.getInt("dungeon.height"));

            // load dungeon.txt
            std::string dungeonPath{basePath + "/dungeon.txt"};
            std::ifstream dungeonFile{dungeonPath};

            std::string cur;
            int curFloor;
            while(dungeonFile >> cur) {
                if (cur == "F") {
                    dungeonFile >> curFloor;
                } else if(cur == "R") {
                    Point roomPosition{0, 0};
                    dungeonFile >> roomPosition;
                    dungeonFile >> cur;

                    dc::model::Room *room = dungeon->floor(curFloor - 1).rooms()[roomPosition.y()][roomPosition.x()];
                    room->setVisited(true);

                    // read traps
                    room->traps().clear();
                    while(dungeonFile >> cur) {
                        if(cur == ";")
                            break;

                        dc::model::Trap *trap = mTrapLoader.createTrap(cur);
                        dungeonFile >> *trap;
                        room->traps().push_back(trap);
                    }

                    // read mobs
                    room->mobs().clear();
                    while(dungeonFile >> cur) {
                        if(cur == ";")
                            break;

                        int mobId = Number::toInt(cur);
                        int mobLevel;
                        dungeonFile >> mobLevel;
                        dc::model::Mob *mob = mMobGenerator.create(mobId, mobLevel);

                        int mobHealth;
                        dungeonFile >> mobHealth;
                        mob->setHealth(mobHealth);

                        room->mobs().push_back(mob);
                    }
                }
            }

            // load player.txt
            std::string playerPath{basePath + "/player.txt"};
            std::ifstream playerFile{playerPath};

            model::Player *player = new model::Player();
            playerFile >> *player;

            // read item id
            int itemId;
            playerFile >> itemId;

            if(itemId != 0) {
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

            // load inventory.txt
            std::string inventoryPath{basePath + "/inventory.txt"};
            std::ifstream inventoryFile{inventoryPath};

            unsigned int invItemId;
            while(inventoryFile >> invItemId) {
                player->inventory().add(*mItemLoader.createItem(invItemId));
            }

            // add standard items
            model::Item *iconograph = new Iconograph();
            player->inventory().addItem(*iconograph);

            model::Item *grenade = new model::Grenade();
            player->inventory().addItem(*grenade);

            model::Item *talisman = new model::Talisman();
            player->inventory().addItem(*talisman);

            model::Item *compass = new model::Compass();
            player->inventory().addItem(*compass);

            dc::model::Game *game = new dc::model::Game(seed, dungeon, player);
            ServiceLocator::getInstance().addInstance<dc::model::Game>(*game);

            mGameLoop.pushState(new GameplayState(game));
        }

        LoadGameCommand *LoadGameCommand::create() {
            ServiceLocator &sl = ServiceLocator::getInstance();

            dc::game::GameLoop &gameLoop = sl.resolve<dc::game::GameLoop>();
            dc::game::ItemLoader &itemLoader = sl.resolve<dc::game::ItemLoader>();
            dc::game::TrapLoader &trapLoader = sl.resolve<dc::game::TrapLoader>();
            dc::game::MobGenerator &mobGenerator = sl.resolve<dc::game::MobGenerator>();

            return new LoadGameCommand(gameLoop, itemLoader, trapLoader, mobGenerator);
        }

        bool LoadGameCommand::isAction() const {
            return false;
        }
    }
}
