#include <algorithm>
#include "Room.h"
#include "Trap.h"

namespace dc {
    namespace model {
        Room::Room(std::string name, std::string description) : Room(Point(0, 0), name, description) {

        }

        Room::Room(Point position, std::string name, std::string description) : Room(position, name, description, false) {

        }

        Room::Room(Point position, std::string name, std::string description, bool visited) : Room(position, name, description, visited, std::vector<Trap*>()) {

        }

        Room::Room(Point position, std::string name, std::string description, bool visited, std::vector<Trap*> traps) :
                mPosition(position),
                mName(name),
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

        const std::string &Room::name() const {
            return mName;
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

        Inventory &Room::inventory() {
            return mInventory;
        }

        const std::vector<Trap*> &Room::traps() const {
            return mTraps;
        }

        void Room::addTrap(Trap *trap) {
            mTraps.push_back(trap);
        }

        const std::vector<Mob*> &Room::mobs() const {
            return mMobs;
        }

        void Room::addMob(Mob *mob) {
            mMobs.push_back(mob);
        }

        void Room::removeMob(Mob *mob) {
            mMobs.erase(std::remove(mMobs.begin(), mMobs.end(), mob), mMobs.end());
        }
    }
}
