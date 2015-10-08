#include "Room.h"

namespace dc {
    namespace model {
        Room::Room(std::string description, bool visited, Passage &north, Passage &east, Passage &south, Passage &west, std::vector<Trap*> traps) :
                mDescription(description),
                mVisited(visited),
                mNorth(north),
                mEast(east),
                mSouth(south),
                mWest(west),
                mTraps(traps) {

        }

        Room::~Room() {
            for(std::vector<model::Trap*>::iterator it = mTraps.begin(); it != mTraps.end(); ++it) {
                delete *it;
            }
        }
    }
}
