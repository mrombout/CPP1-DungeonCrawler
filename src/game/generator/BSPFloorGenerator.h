#ifndef DUNGEONCRAWLER_DFSFLOORGENERATOR_H
#define DUNGEONCRAWLER_DFSFLOORGENERATOR_H

#include "Floor.h"
#include "FloorGenerator.h"
#include "RoomGenerator.h"
#include "Leaf.h"

/**
 * Generates a dungeon floor by using binary space partitioning to divide the room in several pieces. Then each smallest
 * piece gets a randomly sized room that must fit inside its space. Than for each node that has both a left and a right
 * child a hallway is added in between them.
 */
class BSPFloorGenerator : public FloorGenerator {
public:
    BSPFloorGenerator(RoomGenerator &roomGenerator);

    /**
     * Generates a dungeon floor using binary space partitioning to lay out the rooms.
     */
    virtual dc::model::Floor *generate(unsigned int level) override;

    /**
     * Create dungeon rooms for the rooms and halls in the given Leaf.
     */
    void createRooms(std::vector<std::vector<dc::model::Room*>> &vector, Leaf *leaf, unsigned int &level);

    /**
     * Create dungeon rooms for the given rectangle.
     */
    void createRectangle(std::vector<std::vector<dc::model::Room*>> &vector, dc::Rectangle *rectangle, unsigned int &level);

    /**
     * Create a tree that is divided up using binary space partitioning.
     */
    Leaf *createTree();

private:
    static int MAX_LEAF_SIZE;

    RoomGenerator &mRoomGenerator;

    void connectRooms(std::vector<std::vector<dc::model::Room *>> vector);

    dc::model::Room *determineStaircaseUp(std::vector<std::vector<dc::model::Room*>> &vector, Leaf *root);
    dc::model::Room *determineStaircaseDown(std::vector<std::vector<dc::model::Room*>> &vector, Leaf *root);
};

#endif //DUNGEONCRAWLER_DFSFLOORGENERATOR_H
