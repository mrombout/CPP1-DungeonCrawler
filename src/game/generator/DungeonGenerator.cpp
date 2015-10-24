#include <string.h>
#include <stdlib.h>
#include "DungeonGenerator.h"
#include "StringGenerator.h"

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

DungeonGenerator::DungeonGenerator(FloorGenerator &floorGenerator) :
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

    if(rand() % 100 > 50) {
        std::vector<std::vector<std::string>> source{
            dungeonTypes,
            dungeonAdjective,
            dungeonNoun
        };
        std::vector<std::string> words = StringGenerator::generate(source, seed);

        dungeonName.append(words[0]);
        dungeonName.append(" of the ");
        dungeonName.append(words[1] + " ");
        dungeonName.append(words[2]);
    } else {
        std::vector<std::vector<std::string>> source{
                dungeonAdjective,
                dungeonTypes
        };
        std::vector<std::string> words = StringGenerator::generate(source, seed);

        dungeonName.append("The ");
        dungeonName.append(words[0]);
        dungeonName.append(words[1]);
    }

    return dungeonName;
}

Floor *DungeonGenerator::generateDungeonFloor(unsigned int seed, int level) const {
    return mFloorGenerator.generate(seed, level);
}
