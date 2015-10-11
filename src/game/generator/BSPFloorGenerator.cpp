#include <stdlib.h>
#include "BSPFloorGenerator.h"
#include "Leaf.h"

dc::model::Floor  *BSPFloorGenerator::generate(unsigned int seed) {
    std::vector<Leaf*> leafs;

    Leaf *root = new Leaf(0, 0, 25, 25);
    leafs.push_back(root);

    bool didSplit = true;
    while(didSplit) {
        didSplit = false;
        for(Leaf *leaf : leafs) {
            if(leaf->leftChild() == nullptr && leaf->rightChild() == nullptr) {
                if (leaf->width() > 5 || leaf->height() > 5 || rand() > 0.25)
                {
                    if(leaf->split(seed)) {
                        leafs.push_back(leaf->leftChild());
                        leafs.push_back(leaf->rightChild());
                        didSplit = true;
                    }
                }
            }
        }
    }

    root->createRooms(seed);
}
