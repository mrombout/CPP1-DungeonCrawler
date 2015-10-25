#include "Floor.h"
#include "Room.h"

namespace dc {
    namespace model {
        int Floor::level() const {
            return mLevel;
        }

        Floor::Floor(int level, std::vector<std::vector<Room *>> rooms, Room* startRoom, Room*exitRoom) :
            mLevel(level),
            mStartRoom(startRoom),
            mExitRoom(exitRoom) {
            mRooms = rooms;

            for(std::vector<Room*> row : rooms) {
                for(Room* room : row) {
                    if(room)
                        room->setFloor(this);
                }
            }
        }

        Floor::~Floor() {

        }

        Room &Floor::startRoom() const {
            return *mStartRoom;
        }

        Room &Floor::exitRoom() const {
            return *mExitRoom;
        }

        unsigned int Floor::width() const {
            return mRooms[0].size();
        }

        unsigned int Floor::height() const {
            return mRooms.size();
        }

        const std::vector<std::vector<Room *>> &Floor::rooms() const {
            return mRooms;
        }
    }
}