#include <iostream>
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
#include "item/HealthPotion.h"
#include "util/ServiceLocator.h"
#include "util/console.h"
#include "util/Render.h"

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
            dc::game::GameLoop &gameLoop = ServiceLocator::getInstance().resolve<dc::game::GameLoop>();
            dc::model::Game &game = ServiceLocator::getInstance().resolve<dc::model::Game>();
            dc::model::Player &player = game.player();

            if(!Render::prompt(player, gameLoop))
                return "";

            std::string input;
            while(input.empty())
                std::getline(std::cin, input);

            return input;
        }

        game::Command *GameplayState::onEval(std::string input) {
            game::Command *command = mCommandManager.create(input);
            return command;
        }

        void GameplayState::onPrint(game::GameLoop &game, game::Command *command) {
            command->execute();
            if(!command->isAction())
                return;

            mGame->player().increaseMana(1);
            updateEnemies(game);
        }

        void GameplayState::updateEnemies(game::GameLoop &game) const {
            std::cout << csl::color(csl::WHITE) << "The enemies scuffle about." << std::endl;

            // enter combat
            const std::vector<dc::model::Mob*> &mobs = mGame->player().room()->mobs();
            if(!mobs.empty()) {
                game.pushState(new CombatState(*mGame));
            }

            // tick current room
            dc::model::Room *room = mGame->player().room();
            room->tickMobs(mGame->player());

            // tick adjacent rooms
            std::vector<dc::model::Passage*> adjPassages = room->adjacantPassages();
            for(dc::model::Passage* passage : adjPassages) {
                passage->otherSide(*room).tickMobs(mGame->player());
            }
        }
    }
}