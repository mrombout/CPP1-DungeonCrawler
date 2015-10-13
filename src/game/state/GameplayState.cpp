#include <Sword.h>
#include "GameplayState.h"
#include "CommandParameters.h"
#include "Game.h"
#include "Player.h"
#include "Dungeon.h"
#include "Floor.h"
#include "Room.h"
#include "Passage.h"
#include "Trap.h"
#include "command/NullCommand.h"

namespace dc {
    namespace game {
        GameplayState::GameplayState() :
            mCommandManager() {

        }

        void GameplayState::onInitialize(engine::GameLoop *game) {
            std::vector<model::Room*> rooms = std::vector<model::Room*>();
            model::Room *roomA = new model::Room("Description A", true, std::vector<model::Trap*>());
            model::Room *roomB = new model::Room("Description B", true, std::vector<model::Trap*>());
            model::Passage *passageAB = new model::Passage(*roomA, *roomB);

            rooms.push_back(roomA);
            rooms.push_back(roomB);


            std::vector<model::Floor*> floors = std::vector<model::Floor*>();
            model::Floor *floor = new model::Floor(0, rooms);
            floors.push_back(floor);

            model::Dungeon *dungeon = new model::Dungeon(0, "Dungeon 1", floors);

            std::vector<model::Item*> items = std::vector<model::Item*>();

            model::Item *item = new model::Sword("A Sword");
            items.push_back(item);

            model::Inventory *inventory = new model::Inventory(items);

            model::Player *player = new model::Player(*roomA, inventory);

            mGame = new model::Game(dungeon, player);
        }

        void GameplayState::onEnter(engine::GameLoop *game) {
            std::cout << mGame->player().room().description() << std::endl;
        }

        std::string GameplayState::onRead() {
            std::string input;
            std::cin >> input;
            return input;
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
        }
    }
}