#ifndef DUNGEONCRAWLER_ROOMGENERATOR_H
#define DUNGEONCRAWLER_ROOMGENERATOR_H

static const int VARIANCE = 1;

#include "Room.h"

/**
 * Generates a random room containing a random number of enemies, traps and
 * loot. Each room gets a random description.
 */
class RoomGenerator {
public:
    dc::model::Room *generate(unsigned int seed, unsigned int level);
};


#endif //DUNGEONCRAWLER_ROOMGENERATOR_H
