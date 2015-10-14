#ifndef DUNGEONCRAWLER_ROOMGENERATOR_H
#define DUNGEONCRAWLER_ROOMGENERATOR_H

#include "Room.h"

/**
 * Generates a random room containing a random number of enemies, traps and
 * loot. Each room gets a random description.
 */
class RoomGenerator {
public:
    dc::model::Room *generate(unsigned int seed);
};


#endif //DUNGEONCRAWLER_ROOMGENERATOR_H
