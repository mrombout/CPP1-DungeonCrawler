#include "Floor.h"

namespace dc {
    namespace model {
        int Floor::level() const {
            return mLevel;
        }

        Floor::Floor(int level, std::vector<Room *> rooms) :
            mLevel(level),
            mRooms(rooms) {

        }

        Floor::~Floor() {
            for(std::vector<model::Room*>::iterator it = mRooms.begin(); it != mRooms.end(); ++it) {
                delete *it;
            }
        }
    }
}