#ifndef DUNGEONCRAWLER_DUNGEONGENERATOR_H
#define DUNGEONCRAWLER_DUNGEONGENERATOR_H

#include <Dungeon.h>
#include "SimpleFloorGenerator.h"

/**
 * Generates a new dungeon consisting of a random number of floors.
 */
class DungeonGenerator {
public:
    DungeonGenerator(SimpleFloorGenerator &floorGenerator);

    dc::model::Dungeon *generate(unsigned int seed) const;

private:
    std::string generateDungeonName(unsigned int seed) const;
    dc::model::Floor *generateDungeonFloor(unsigned int seed, int level) const;

    SimpleFloorGenerator &mFloorGenerator;
};


#endif //DUNGEONCRAWLER_DUNGEONGENERATOR_H
