#include <stdlib.h>
#include <iostream>
#include "SimpleFloorGenerator.h"

using namespace dc::model;

namespace dc {
    namespace game {
        SimpleFloorGenerator::SimpleFloorGenerator(RoomGenerator &roomGenerator) :
                mRoomGenerator(roomGenerator),
                mWidth(0),
                mHeight(0) {

        }

        Floor *SimpleFloorGenerator::generate(unsigned int level) {
            // reset state
            reset();

            // determine start position
            Point startPosition(0, 0);
            if(level % 2 == 0) {
                startPosition = Point(mWidth - 1, mHeight - 1);;
            }

            Room *exit = createRoom(level);
            exit->setPosition(startPosition);

            // start digging floor
            dig(exit, startPosition, level);

            // create floor
            Room* startRoom = mGrid[0][0];
            Room* exitRoom = mGrid[mWidth - 1][mHeight - 1];
            if(level % 2 == 0) {
                Room* tmp = startRoom;
                startRoom = exitRoom;
                exitRoom = tmp;
            }

            std::cout << "Done generating dungeon" << std::endl;
            return new Floor(level, mGrid, startRoom, exitRoom);
        }

        void SimpleFloorGenerator::reset() {
            // create a new array of a new size
            mWidth = 5;
            mHeight = 5;

            mGrid.resize(mHeight);
            for(int i = 0; i < mHeight; ++i) {
                mGrid[i].resize(mWidth, nullptr);
            }
        }

        void SimpleFloorGenerator::dig(Room *room, Point point, unsigned int &level) {
            mGrid[point.y()][point.x()] = room;

            Room *currentRoom = room;
            Point currentPoint = point;
            Passage::Direction direction = getRandomNeighbour(*currentRoom, point);
            while(direction != Passage::Direction::Unknown) {
                Room *nextRoom = createRoom(level);
                Passage *passage = new Passage(*currentRoom, *nextRoom);

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

                nextRoom->setPosition(point);
                dig(nextRoom, point, level);
                std::cout << "unwinding" << std::endl;

                point = currentPoint;
                direction = getRandomNeighbour(*currentRoom, currentPoint);
            }

            std::cout << "End looping" << std::endl;
        }

        Room * SimpleFloorGenerator::createRoom(unsigned int &level) {
            return mRoomGenerator.generate(level);
        }

        bool SimpleFloorGenerator::isVisited(int x, int y) const {
            int xIndex = x;
            int yIndex = y;

            if(xIndex < 0 || xIndex > mWidth || yIndex < 0 || yIndex > mHeight)
                return true;
            return mGrid[yIndex][xIndex] != nullptr;
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
    }
}
