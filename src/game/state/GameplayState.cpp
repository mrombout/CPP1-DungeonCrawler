#include <iostream>
#include "generator/MobGenerator.h"
#include "Sword.h"
#include "generator/SimpleFloorGenerator.h"
#include "generator/DungeonGenerator.h"
#include "GameplayState.h"
#include "Game.h"
#include "Trap.h"
#include "command/NullCommand.h"
#include "CombatState.h"

namespace dc {
    namespace game {
        GameplayState::GameplayState() :
            mCommandManager() {

        }

        GameplayState::~GameplayState() {
            delete mGame;
        }


        void GameplayState::onInitialize(engine::GameLoop *game) {
            // generate random dungeon
            unsigned int seed = 1;

            MobGenerator mobGenerator;
            RoomGenerator roomGenerator(mobGenerator);
            SimpleFloorGenerator floorGenerator = SimpleFloorGenerator(roomGenerator);
            DungeonGenerator dungeonGenerator(floorGenerator);
            model::Dungeon* dungeon = dungeonGenerator.generate(seed);

            std::vector<model::Item*> items = std::vector<model::Item*>();
            model::Item *item = new model::Sword("Sword", "A Sword");
            items.push_back(item);

            model::Inventory *inventory = new model::Inventory(items);
            
            model::Player *player = new model::Player(dungeon->floor(0).startRoom(), inventory);

            mGame = new model::Game(dungeon, player);
        }

        void GameplayState::onEnter(engine::GameLoop *game) {
            std::cout << mGame->player().room().description() << std::endl;
        }

        std::string GameplayState::onRead() {
            std::string command;
            std::string argument;

            std::cout << ">";

            std::cin >> command >> argument;

            return command + " " + argument;
        }

        engine::Command *GameplayState::onEval(std::string input) {
            engine::Command *command = mCommandManager.create(input);
            if(!command) {
                std::cout << "Command not recognized" << std::endl;
                // TODO: Cache this NullCommand
                return new NullCommand();
            }

            return command;
        }

        // TODO: Duplicate code in WelcomeState
        void GameplayState::onPrint(engine::GameLoop &game, engine::Command *command) {
            engine::CommandParameters cp(game, mGame->player(), *this);
            command->execute(cp);

            updateEnemies(game);
        }

        void GameplayState::updateEnemies(engine::GameLoop &game) const {
            const std::vector<dc::model::Mob*> &mobs = mGame->player().room().mobs();
            if(!mobs.empty()) {
                game.pushState(new CombatState(*mGame, mobs));
        }
        }
    }
}