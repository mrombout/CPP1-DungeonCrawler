#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>
#include "BSPFloorGenerator.h"
#include "Leaf.h"
#include "Floor.h"
#include "Room.h"

int BSPFloorGenerator::MAX_LEAF_SIZE = 20;

BSPFloorGenerator::BSPFloorGenerator(RoomGenerator &roomGenerator) :
    mRoomGenerator(roomGenerator) {

}

dc::model::Floor *BSPFloorGenerator::generate(unsigned int level) {
    // perform bsp
    Leaf *root = createTree();

    // generate rooms
    std::vector<std::vector<dc::model::Room*>> rooms;
    rooms.resize(root->height());
    for(int i = 0; i < root->height(); ++i) {
        rooms[i].resize(root->width(), nullptr);
    }

    createRooms(rooms, root, level);

    // (debug) render room to console
    std::vector<dc::model::Room*> testRooms;

    for(int y = 0; y < root->height(); ++y) {
        for(int x = 0; x < root->width(); ++x) {
            if(rooms[y][x] == nullptr)
                std::cout << ".";
            else {
                testRooms.push_back(rooms[y][x]);
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }

    // connect all rooms

    return new dc::model::Floor(1, std::vector<std::vector<dc::model::Room*>>(), nullptr, nullptr);
}

void BSPFloorGenerator::createRooms(std::vector<std::vector<dc::model::Room*>> &vector, Leaf *leaf, unsigned int &level) {
    if(leaf->room() != nullptr)
        createRectangle(vector, leaf->room(), level);
    if(!leaf->halls().empty()) {
        for(Rectangle* hall : leaf->halls()) {
            createRectangle(vector, hall, level);
        }
    }

    if(leaf->leftChild() != nullptr)
        createRooms(vector, leaf->leftChild(), level);
    if(leaf->rightChild() != nullptr)
        createRooms(vector, leaf->rightChild(), level);
}

void BSPFloorGenerator::createRectangle(std::vector<std::vector<dc::model::Room*>> &vector, Rectangle *rectangle, unsigned int &level) {
    int left = rectangle->left();
    int top = rectangle->top();
    int bottom = rectangle->bottom();
    int right = rectangle->right();

    for(int y = top; y < bottom; ++y) {
        for(int x = left; x < right; ++x) {
            vector[y][x] = mRoomGenerator.generate(level);
        }
    }
}

Leaf *BSPFloorGenerator::createTree() {
    std::stack<Leaf*> leafs;
    Leaf *root = new Leaf(0, 0, 30, 30);
    leafs.push(root);

    bool didSplit = true;
    while(didSplit) {
        didSplit = false;
        while(!leafs.empty()) {
            Leaf *leaf = leafs.top();
            leafs.pop();

            if(leaf->leftChild() == nullptr && leaf->rightChild() == nullptr) {
                if (leaf->width() > MAX_LEAF_SIZE || leaf->height() > MAX_LEAF_SIZE || rand() % 100 > 25)
                {
                    if(leaf->split()) {
                        leafs.push(leaf->leftChild());
                        leafs.push(leaf->rightChild());
                        didSplit = true;
                    }
                }
            }
        }
    }

    root->createRooms();

    return root;
}
