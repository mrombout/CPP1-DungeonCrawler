#include "Room.h"
#include "Trap.h"

namespace dc {
    namespace model {
        Room::Room(std::string description, bool visited, std::vector<Trap*> traps) :
                mDescription(description),
                mVisited(visited),
                mTraps(traps) {

        }

        Room::~Room() {
            for(std::vector<model::Trap*>::iterator it = mTraps.begin(); it != mTraps.end(); ++it) {
                delete *it;
            }
        }

        // TODO: Kunnen setters van passages niet references vragen? Dan is null check niet nodig.

        void Room::setNorth(Passage *passage) {
            mNorth = passage;
        }

        void Room::setEast(Passage *passage) {
            mEast = passage;
        }

        void Room::setSouth(Passage *passage) {
            mSouth = passage;
        }

        void Room::setWest(Passage *passage) {
            mWest = passage;
        }

        std::string Room::description() const {
            return mDescription;
        }
    }
}
