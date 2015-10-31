#include <iostream>
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

namespace dc {
    namespace game {
        NewGameCommand::NewGameCommand(dc::game::GameLoop &gameLoop) :
                mGameLoop(gameLoop) {

        }

        void NewGameCommand::execute() const {
            // ask for name
            std::cout << "What's your name?";
            std::string name;
            std::cin >> name;

            // ask for seed
            std::cout << "What is your lucky number?";
            std::string strSeed;
            std::cin >> strSeed;

            // generate random dungeon
            int seed = Number::toInt(strSeed);
            ServiceLocator &sl = ServiceLocator::getInstance();
            dc::model::Options &options = sl.resolve<dc::model::Options>();
            dc::game::DungeonGenerator *dungeonGenerator = sl.create<dc::game::DungeonGenerator>();

            model::Dungeon* dungeon = dungeonGenerator->generate(seed, options.getInt("dungeon.width"), options.getInt("dungeon.height"));

            model::Player *player = new model::Player();
            player->setName(name);
            player->setRoom(&dungeon->floor(0).startRoom());

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
    }
}
