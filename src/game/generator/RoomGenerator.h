#ifndef DUNGEONCRAWLER_ROOMGENERATOR_H
#define DUNGEONCRAWLER_ROOMGENERATOR_H

static const int VARIANCE = 1;

#include "Room.h"

class MobGenerator;

/**
 * Generates a random room containing a random number of enemies, traps and
 * loot. Each room gets a random description.
 */
class RoomGenerator {
public:
    RoomGenerator(MobGenerator &mobGenerator);
    dc::model::Room *generate(unsigned int level);

private:
    void generateTraps(dc::model::Room *seed, unsigned int level);
    void generateMobs(dc::model::Room *room, unsigned int level);

    MobGenerator &mMobGenerator;
public:
};


#endif //DUNGEONCRAWLER_ROOMGENERATOR_H
