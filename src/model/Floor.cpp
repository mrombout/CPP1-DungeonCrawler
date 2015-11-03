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
            for(std::vector<Room*> row : mRooms) {
                for(Room* room : row) {
                    if(room) {
                        delete room;
                    }
                }
            }
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

        std::ostream &operator<<(std::ostream &output, const Floor &f) {
            output << std::fixed << std::setprecision(15) << "F" << "\t" << f.mLevel << "\t";

            for(std::vector<dc::model::Room*> row : f.mRooms) {
                for(dc::model::Room* room : row) {
                    if(room && room->isDirty())
                        output << *room;
                }
            }

            return output;
        }

        std::istream &operator>>(std::istream &input, Floor &f) {
            return input;
        }
    }
}