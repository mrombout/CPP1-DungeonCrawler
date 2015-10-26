#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>
#include "BSPFloorGenerator.h"
#include "Leaf.h"
#include "Floor.h"
#include "Room.h"
#include "Passage.h"
#include "util/console.h"
#include "Rectangle.h"

namespace dc {
    namespace game {
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
                    if (rooms[y][x] == nullptr) {
                        csl::log() << ".";
                    } else {
                        testRooms.push_back(rooms[y][x]);
                        csl::log() << "#";
                    }
                }
                csl::log() << std::endl;
            }

            // connect all rooms
            connectRooms(rooms);

            // determine optimal staircases
            dc::model::Room *staircaseUp = determineStaircaseUp(rooms, root);
            dc::model::Room *staircaseDown = determineStaircaseDown(rooms, root);



            return new dc::model::Floor(level, rooms, staircaseUp, staircaseDown);
        }

        void BSPFloorGenerator::createRooms(std::vector<std::vector<dc::model::Room*>> &vector, Leaf *leaf, unsigned int &level) {
            if(leaf->room() != nullptr)
                createRectangle(vector, leaf->room(), level);
            if(!leaf->halls().empty()) {
                for(dc::game::Rectangle* hall : leaf->halls()) {
                    createRectangle(vector, hall, level);
                }
            }

            if(leaf->leftChild() != nullptr)
                createRooms(vector, leaf->leftChild(), level);
            if(leaf->rightChild() != nullptr)
                createRooms(vector, leaf->rightChild(), level);
        }

        void BSPFloorGenerator::createRectangle(std::vector<std::vector<dc::model::Room*>> &vector, dc::game::Rectangle *rectangle, unsigned int &level) {
            int left = rectangle->left();
            int top = rectangle->top();
            int bottom = rectangle->bottom();
            int right = rectangle->right();

            for(int y = top; y < bottom; ++y) {
                for(int x = left; x < right; ++x) {
                    vector[y][x] = mRoomGenerator.generate(level);
                    vector[y][x]->setPosition(Point(x, y));
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

        void BSPFloorGenerator::connectRooms(std::vector<std::vector<dc::model::Room *>> vector) {
            // connect horizontally
            for(int y = 0; y < vector.size() - 1; ++y) {
                for(int x = 0; x < vector[y].size() - 1; ++x) {
                    // connect horizontally
                    dc::model::Room *roomA = vector[y][x];
                    dc::model::Room *roomB = vector[y][x + 1];
                    if(roomA && roomB) {
                        dc::model::Passage *passage = new dc::model::Passage(*roomA, *roomB);
                        roomA->setEast(passage);
                        roomB->setWest(passage);
                    }

                    dc::model::Room *roomC = vector[y + 1][x];
                    // connect vertically
                    if(roomA && roomC) {
                        dc::model::Passage *passage = new dc::model::Passage(*roomA, *roomC);
                        roomA->setSouth(passage);
                        roomC->setNorth(passage);
                    }
                }
            }
        }

        dc::model::Room *BSPFloorGenerator::determineStaircaseUp(std::vector<std::vector<dc::model::Room*>> &vector, Leaf *root) {
            // find smallest leaf on the top left
            Leaf *topLeftRoom = root;
            while(topLeftRoom->leftChild() && topLeftRoom->leftChild()->room()) {
                topLeftRoom = topLeftRoom->leftChild();
            }

            // find room
            dc::game::Rectangle *rect = topLeftRoom->room();
            return vector[rect->top()][rect->left()];
        }

        dc::model::Room *BSPFloorGenerator::determineStaircaseDown(std::vector<std::vector<dc::model::Room*>> &vector, Leaf *root) {
            // Find smallest leaf on the top left
            Leaf *bottomRightRoom = root;
            while(bottomRightRoom->rightChild() && bottomRightRoom->rightChild()->room()) {
                bottomRightRoom = bottomRightRoom->rightChild();
            }

            // find room
            dc::game::Rectangle *rect = bottomRightRoom->room();
            return vector[rect->bottom()][rect->right()];
        }
    }
}
