#include <stdlib.h>
#include <iostream>
#include "SimpleFloorGenerator.h"
#include "Leaf.h"
#include "Room.h"
#include "Point.h"
#include "Passage.h"

using namespace dc::model;

Floor *SimpleFloorGenerator::generate(unsigned int seed, int level) {
    Room *exit = new Room("Exit Thingy!");

    mWidth = 5;
    mHeight = 5;

    mGrid = new bool*[mHeight];
    for(int i = 0; i < mHeight; ++i) {
        mGrid[i] = new bool[mWidth];
        std::fill_n(mGrid[i], mWidth, false);
    }

    Point *startPosition = nullptr;
    if(level % 2 == 0) {
        startPosition = new Point(0, 0);
    } else {
        startPosition = new Point(mWidth, mHeight);
    }

    dig(exit, *startPosition);

    std::cout << "Done generating dungeon" << std::endl;
}

void SimpleFloorGenerator::dig(dc::model::Room *room, Point point) {
    mGrid[point.x() - 1][point.y() - 1] = true;

    dc::model::Room *currentRoom = room;
    Direction direction = getRandomNeighbour(*currentRoom, point);
    while(direction != NONE) {
        Room *nextRoom = new Room("Random room description!");
        Passage *passage = new Passage(*currentRoom, *nextRoom);
        switch(direction) {
            case NORTH:
                std::cout << "Diggin north" << std::endl;
                currentRoom->setNorth(passage);
                nextRoom->setSouth(passage);
                point.setY(point.y() - 1);
                break;
            case EAST:
                std::cout << "Diggin east" << std::endl;
                currentRoom->setEast(passage);
                nextRoom->setWest(passage);
                point.setX(point.x() + 1);
                break;
            case SOUTH:
                std::cout << "Diggin south" << std::endl;
                currentRoom->setSouth(passage);
                nextRoom->setNorth(passage);
                point.setY(point.y() + 1);
                break;
            case WEST:
                std::cout << "Diggin west" << std::endl;
                currentRoom->setWest(passage);
                nextRoom->setEast(passage);
                point.setX(point.x() - 1);
                break;
            default:
                break;
        }

        dig(nextRoom, point);
        std::cout << "unwinding" << std::endl;

        direction = getRandomNeighbour(*currentRoom, point);
    }

    std::cout << "End looping" << std::endl;
}

SimpleFloorGenerator::Direction SimpleFloorGenerator::getRandomNeighbour(Room room, Point &point) {
    std::vector<Direction> directions = std::vector<Direction>();

    if(!room.north() && point.y() > 0 && !isVisited(point.x(), point.y() - 1))
        directions.push_back(NORTH);
    if(!room.east() && point.x() < mWidth && !isVisited(point.x() + 1, point.y()))
        directions.push_back(EAST);
    if(!room.south() && point.y() < mHeight && !isVisited(point.x(), point.y() + 1))
        directions.push_back(SOUTH);
    if(!room.west() && point.x() > 0 && !isVisited(point.x() - 1, point.y()))
        directions.push_back(WEST);

    if(directions.empty())
        return NONE;
    return directions[rand() % directions.size()];
}

bool SimpleFloorGenerator::isVisited(int x, int y) {
    int xIndex = x - 1;
    int yIndex = y - 1;

    if(xIndex < 0 || xIndex > mWidth || yIndex < 0 || yIndex > mHeight)
        return true;
    return mGrid[xIndex][yIndex];
}