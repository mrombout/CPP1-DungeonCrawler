#include <stdlib.h>
#include "fixture/Ladder.h"
#include "DungeonGenerator.h"
#include "Dungeon.h"
#include "FloorGenerator.h"
#include "StringGenerator.h"
#include "Floor.h"
#include "Room.h"

using namespace dc::model;

std::vector<std::string> dungeonTypes = {
    "Point",
    "Delves",
    "Quarters",
    "Cells",
    "Maze",
    "Vault",
    "Caves",
    "Quarry"
};

std::vector<std::string> dungeonAdjective {
    "Frozen",
    "Scourged",
    "Mythic",
    "Uncanny",
    "Foul",
    "Octarine",
    "Twisted",
    "Nether",
    "Goblin",
    "Serene",
    "Fabled"
};

std::vector<std::string> dungeonNoun {
    "Priest",
    "Scorpion",
    "Mountain",
    "Prison",
    "Warlock",
    "King",
    "Kaizar",
    "Warmonger",
    "Wizard",
    "Order"
};

namespace dc {
    namespace game {
        DungeonGenerator::DungeonGenerator(FloorGenerator &floorGenerator) :
                mFloorGenerator(floorGenerator) {

        }

        model::Dungeon *DungeonGenerator::generate(unsigned int seed) const {
            srand(seed);

            std::string dName = generateDungeonName();
            std::vector<Floor*> dFloors = std::vector<Floor*>();

            //int numFloors = rand() % 10 + 1;
            Floor *previousFloor = nullptr;
            Floor *currentFloor = nullptr;
            int numFloors = 2;
            for(int i = 1; i <= numFloors; ++i) {
                previousFloor = currentFloor;
                currentFloor = generateDungeonFloor(i);
                dFloors.push_back(currentFloor);

                if(previousFloor) {
                    Room &previousStart = previousFloor->startRoom();
                    Room &previousEnd = previousFloor->exitRoom();
                    Room &currentStart = currentFloor->startRoom();
                    Room &currentExit = currentFloor->exitRoom();

                    // connect currentStart to previousEnd
                    Ladder *ladderToCurrentStart = new dc::model::Ladder(dc::model::Ladder::Direction::DOWN, currentStart);
                    Ladder *ladderToPreviousEnd = new dc::model::Ladder(dc::model::Ladder::Direction::UP, previousEnd);

                    currentStart.inventory().addItem(*ladderToPreviousEnd);
                    previousEnd.inventory().addItem(*ladderToCurrentStart);
                }
            }

            return new Dungeon(seed, dName, dFloors);
        }

        std::string DungeonGenerator::generateDungeonName() const {
            std::string dungeonName;

            if(rand() % 100 > 50) {
                std::vector<std::vector<std::string>> source{
                        dungeonTypes,
                        dungeonAdjective,
                        dungeonNoun
                };
                std::vector<std::string> words = StringGenerator::generate(source);

                dungeonName.append(words[0]);
                dungeonName.append(" of the ");
                dungeonName.append(words[1] + " ");
                dungeonName.append(words[2]);
            } else {
                std::vector<std::vector<std::string>> source{
                        dungeonAdjective,
                        dungeonTypes
                };
                std::vector<std::string> words = StringGenerator::generate(source);

                dungeonName.append("The ");
                dungeonName.append(words[0]);
                dungeonName.append(words[1]);
            }

            return dungeonName;
        }

        Floor *DungeonGenerator::generateDungeonFloor(int level) const {
            return mFloorGenerator.generate(level);
        }
    }
}
