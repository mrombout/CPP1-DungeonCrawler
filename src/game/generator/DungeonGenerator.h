#ifndef DUNGEONCRAWLER_DUNGEONGENERATOR_H
#define DUNGEONCRAWLER_DUNGEONGENERATOR_H

#include <Dungeon.h>
#include "FloorGenerator.h"

/**
 * Generates a new dungeon consisting of a random number of floors.
 */
class DungeonGenerator {
public:
    DungeonGenerator(FloorGenerator &floorGenerator);

    dc::model::Dungeon *generate(unsigned int seed) const;

private:
    std::string generateDungeonName(unsigned int seed) const;
    dc::model::Floor *generateDungeonFloor(unsigned int seed, int level) const;

    FloorGenerator &mFloorGenerator;
};


#endif //DUNGEONCRAWLER_DUNGEONGENERATOR_H
