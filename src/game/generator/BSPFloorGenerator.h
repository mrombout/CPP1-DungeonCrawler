#ifndef DUNGEONCRAWLER_DFSFLOORGENERATOR_H
#define DUNGEONCRAWLER_DFSFLOORGENERATOR_H

#include "Floor.h"
#include "FloorGenerator.h"
#include "Leaf.h"

class BSPFloorGenerator : public FloorGenerator {
    static int MAX_LEAF_SIZE;

    virtual dc::model::Floor *generate(unsigned int seed, unsigned int level) override;

    void createRooms(std::vector<std::vector<dc::model::Room *>> &vector, Leaf *leaf);
    void createRectangle(std::vector<std::vector<dc::model::Room *>> &vector, Rectangle *pRectangle);
};

#endif //DUNGEONCRAWLER_DFSFLOORGENERATOR_H
