#include <stdlib.h>
#include "item/Prop.h"
#include "fixture/Ladder.h"
#include "DungeonGenerator.h"
#include "Dungeon.h"
#include "FloorGenerator.h"
#include "StringGenerator.h"
#include "Floor.h"
#include "Room.h"
#include "generator/MobGenerator.h"

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
        DungeonGenerator::DungeonGenerator(FloorGenerator *floorGenerator, MobGenerator &mobGenerator) :
                mFloorGenerator(floorGenerator),
                mMobGenerator(mobGenerator) {

        }

        DungeonGenerator::~DungeonGenerator() {
            delete mFloorGenerator;
        }

        model::Dungeon *DungeonGenerator::generate(unsigned int seed, unsigned int width, unsigned int height) const {
            srand(seed);

            std::string dName = generateDungeonName();
            std::vector<Floor*> dFloors = std::vector<Floor*>();

            int numFloors = rand() % 10 + 1;
            Floor *previousFloor = nullptr;
            Floor *currentFloor = nullptr;
            for(int i = 1; i <= numFloors; ++i) {
                previousFloor = currentFloor;
                currentFloor = generateDungeonFloor(i, width, height);
                dFloors.push_back(currentFloor);

                if(!previousFloor) {
                    currentFloor->startRoom().inventory().addItem(new Prop(-1, "Breadcrumb", "Oh! It's that breadcrumb I left here so I can find my way back!"));
                } else {
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

            currentFloor->exitRoom().addMob(mMobGenerator.generate(11));

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

        Floor *DungeonGenerator::generateDungeonFloor(int level, unsigned int width, unsigned int height) const {
            return mFloorGenerator->generate(level, width, height);
        }
    }
}
