#ifndef DUNGEONCRAWLER_BSPFLOORGENERATOR_H
#define DUNGEONCRAWLER_BSPFLOORGENERATOR_H

#include <vector>
#include <Room.h>
#include "Floor.h"
#include "FloorGenerator.h"
#include "Point.h"

/**
 * Generates a random floor consisting of a random number of rooms in a random
 * layout using a simple algorithm inspired by the depth-first search
 * algorithm.
 */
class SimpleFloorGenerator : public FloorGenerator {
public:
    dc::model::Floor *generate(unsigned int seed, int level) override;

private:
    int mWidth;
    int mHeight;

    bool** mGrid;

    enum Direction {
        NORTH,
        EAST,
        SOUTH,
        WEST,
        NONE
    };

    void dig(dc::model::Room *room, Point point);

    SimpleFloorGenerator::Direction getRandomNeighbour(dc::model::Room room, Point &point);

    bool isVisited(int x, int y);
};


#endif //DUNGEONCRAWLER_BSPFLOORGENERATOR_H
