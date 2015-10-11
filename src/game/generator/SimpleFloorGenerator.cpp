#include <stdlib.h>
#include <iostream>
#include "SimpleFloorGenerator.h"
#include "Room.h"
#include "Point.h"
#include "Passage.h"

using namespace dc::model;

SimpleFloorGenerator::SimpleFloorGenerator() :
	mGrid(nullptr),
	mWidth(0),
	mHeight(0) {

}

Floor *SimpleFloorGenerator::generate(unsigned int seed, int level) {
	Room *exit = createRoom();

	// reset state
	reset();

    // determine start position
    Point startPosition(0, 0);
    if(level % 2 == 0) {
        startPosition = Point(mWidth - 1, mHeight - 1);
    }

    // start digging
    dig(exit, startPosition);

    std::cout << "Done generating dungeon" << std::endl;
	return new Floor(level, mRooms);
}

void SimpleFloorGenerator::reset() {
	if (mGrid != nullptr) {
		// delete the old array
		for (int i = 0; i < mHeight; ++i)
			delete[] mGrid[i];
		delete[] mGrid;
	}
	if (!mRooms.empty()) {
		mRooms.clear();
	}

	// create a new array of a new size
	mWidth = 5;
	mHeight = 5;

	mGrid = new bool*[mHeight];
	for (int i = 0; i < mHeight; ++i) {
		mGrid[i] = new bool[mWidth];
		std::fill_n(mGrid[i], mWidth, false);
	}
}

void SimpleFloorGenerator::dig(Room *room, Point point) {
    mGrid[point.x()][point.y()] = true;

    Room *currentRoom = room;
	Point currentPoint = point;
    Passage::Direction direction = getRandomNeighbour(*currentRoom, point);
    while(direction != Passage::Direction::Unknown) {
		Room *nextRoom = createRoom();
        Passage *passage = new Passage(direction, *currentRoom, *nextRoom);
        switch(direction) {
            case Passage::Direction::North:
                std::cout << "Diggin north" << std::endl;
                currentRoom->setNorth(passage);
                nextRoom->setSouth(passage);
                point.setY(point.y() - 1);
                break;
            case Passage::Direction::East:
                std::cout << "Diggin east" << std::endl;
                currentRoom->setEast(passage);
                nextRoom->setWest(passage);
                point.setX(point.x() + 1);
                break;
            case Passage::Direction::South:
                std::cout << "Diggin south" << std::endl;
                currentRoom->setSouth(passage);
                nextRoom->setNorth(passage);
                point.setY(point.y() + 1);
                break;
            case Passage::Direction::West:
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

		point = currentPoint;
        direction = getRandomNeighbour(*currentRoom, currentPoint);
    }

    std::cout << "End looping" << std::endl;
}

Room* SimpleFloorGenerator::createRoom() {
	Room* newRoom = new Room("Some Random description " + std::to_string(mRooms.size() + 1));
	mRooms.push_back(newRoom);
	return newRoom;
}

bool SimpleFloorGenerator::isVisited(int x, int y) const {
    int xIndex = x;
    int yIndex = y;

    if(xIndex < 0 || xIndex > mWidth || yIndex < 0 || yIndex > mHeight)
        return true;
    return mGrid[xIndex][yIndex];
}

Passage::Direction SimpleFloorGenerator::getRandomNeighbour(const Room &room, const Point &point) const {
    std::vector<Passage::Direction> directions = std::vector<Passage::Direction>();

    if(!room.north() && point.y() >= 0 && !isVisited(point.x(), point.y() - 1))
        directions.push_back(Passage::Direction::North);
    if(!room.east() && point.x() < mWidth - 1 && !isVisited(point.x() + 1, point.y()))
        directions.push_back(Passage::Direction::East);
    if(!room.south() && point.y() < mHeight - 1 && !isVisited(point.x(), point.y() + 1))
        directions.push_back(Passage::Direction::South);
    if(!room.west() && point.x() >= 0 && !isVisited(point.x() - 1, point.y()))
        directions.push_back(Passage::Direction::West);

    if(directions.empty())
        return Passage::Direction::Unknown;
    return directions[rand() % directions.size()];
}
