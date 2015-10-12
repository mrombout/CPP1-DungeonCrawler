#include "Room.h"
#include "Trap.h"

namespace dc {
    namespace model {
        Room::Room(Point position, std::string description) :Room(position, description, false) {

        }

        Room::Room(Point position, std::string description, bool visited) : Room(position, description, visited, std::vector<Trap*>()) {

        }

        Room::Room(Point position, std::string description, bool visited, std::vector<Trap*> traps) :
                mPosition(position),
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

	    bool Room::isVisited() const {
			return mVisited;
	    }

        const Point &Room::position() const {
            return mPosition;
        }

	    std::string Room::description() const {
            return mDescription;
        }

	    std::vector<Passage*> Room::adjacantPassages() const {
			std::vector<Passage*> passages;

            passages.push_back(north());
            passages.push_back(east());
            passages.push_back(south());
            passages.push_back(west());

			return passages;
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

        Floor *Room::floor() const {
            return mFloor;
        }

        void Room::setFloor(Floor *floor) {
            mFloor = floor;
        }

        void Room::setPosition(Point point) {
            mPosition = point;
        }
    }
}
