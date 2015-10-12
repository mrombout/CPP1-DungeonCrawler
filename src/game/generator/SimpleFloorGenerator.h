#ifndef DUNGEONCRAWLER_BSPFLOORGENERATOR_H
#define DUNGEONCRAWLER_BSPFLOORGENERATOR_H

#include <vector>
#include <Room.h>
#include "Floor.h"
#include "FloorGenerator.h"
#include "Point.h"
#include "RoomGenerator.h"
#include "Passage.h"

/**
 * Generates a random floor consisting of a random number of rooms in a random
 * layout using a simple algorithm inspired by the depth-first search
 * algorithm.
 */
class SimpleFloorGenerator : public FloorGenerator {
public:
    explicit SimpleFloorGenerator();

	dc::model::Floor *generate(unsigned int seed, int level) override;

private:
    unsigned int mWidth;
    unsigned int mHeight;

    std::vector<std::vector<dc::model::Room*>> mGrid;

	RoomGenerator mRoomGenerator;

    void dig(dc::model::Room *room, Point point);
	void reset();

	dc::model::Room *createRoom();

    dc::model::Passage::Direction getRandomNeighbour(const dc::model::Room &room, const Point &point) const;
    bool isVisited(int x, int y) const;
};


#endif //DUNGEONCRAWLER_BSPFLOORGENERATOR_H
