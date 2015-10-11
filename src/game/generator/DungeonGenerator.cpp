#include <string.h>
#include <stdlib.h>
#include <util/Random.h>
#include "DungeonGenerator.h"

using namespace dc::model;

std::string dungeonTypes[] = {
    "Point",
    "Delves",
    "Quarters",
    "Cells",
    "Maze",
    "Vault",
    "Caves",
    "Quarry"
};

std::string dungeonAdjective[] {
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

std::string dungeonNoun[] {
    "Priest",
    "Scorpion",
    "Mountain",
    "Cells",
    "Warlock",
    "King",
    "Kaizar",
    "Warmonger",
    "Wizard",
    "Order"
};

DungeonGenerator::DungeonGenerator(SimpleFloorGenerator &floorGenerator) :
        mFloorGenerator(floorGenerator) {

}

Dungeon *DungeonGenerator::generate(unsigned int seed) const {
    std::string dName = generateDungeonName(seed);
    std::vector<Floor*> dFloors = std::vector<Floor*>();

    int numFloors = rand() % 10 + 1;
    for(int i = 1; i <= numFloors; ++i) {
        dFloors.push_back(generateDungeonFloor(seed, i));
    }

    return new Dungeon(seed, dName, dFloors);
}

std::string DungeonGenerator::generateDungeonName(unsigned int seed) const {
    std::string dungeonName;

    if(rand() > .5) {
        dungeonName.append(dungeonTypes[rand() % dungeonTypes->size()]);
        dungeonName.append(" of the ");
        dungeonName.append(dungeonAdjective[rand() % dungeonAdjective->size()] + " ");
        dungeonName.append(dungeonNoun[rand() % dungeonNoun->size()]);
    } else {
        dungeonName.append("The ");
        dungeonName.append(dungeonAdjective[rand() % dungeonAdjective->size()] + " ");
        dungeonName.append(dungeonTypes[rand() % dungeonTypes->size()]);
    }

    return dungeonName;
}

Floor *DungeonGenerator::generateDungeonFloor(unsigned int seed, int level) const {
    return mFloorGenerator.generate(seed, level);
}
