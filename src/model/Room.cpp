#include "Room.h"
#include "Trap.h"

namespace dc {
    namespace model {
        Room::Room(std::string description) : Room(description, false) {

        }

        Room::Room(std::string description, bool visited) : Room(description, visited, std::vector<Trap*>()) {

        }

        Room::Room(std::string description, bool visited, std::vector<Trap*> traps) :
                mDescription(description),
                mVisited(visited),
                mTraps(traps),
                mNorth(nullptr),
                mEast(nullptr),
                mSouth(nullptr),
                mWest(nullptr) {

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

        void Room::setVisited(bool visited) {
            mVisited = visited;
        }

        Passage *Room::north() const {
            return mNorth;
        }

        Passage *Room::east() const {
            return mEast;
        }

        Passage *Room::south() const {
            return mSouth;
        }

        Passage *Room::west() const {
            return mWest;
        }
    }
}
