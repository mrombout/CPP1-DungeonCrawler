#include <algorithm>
#include "fixture/Ladder.h"
#include "Room.h"
#include "Trap.h"
#include "Mob.h"
#include "Passage.h"

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
                mWest(nullptr),
                mIsDirty(false),
                mLighted(false) {

        }

        Room::~Room() {
            for(auto it = mTraps.begin(); it != mTraps.end(); ++it)
                delete *it;
            for(auto it = mMobs.begin(); it != mMobs.end(); ++it)
                delete *it;
            delete mEast;
            delete mSouth;
        }

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

            if(north())
                passages.push_back(north());
            if(east())
                passages.push_back(east());
            if(south())
                passages.push_back(south());
            if(west())
                passages.push_back(west());

            return passages;
        }

        void Room::setVisited(bool visited) {
            mIsDirty = true;
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

        std::vector<Trap*> &Room::traps() {
            return mTraps;
        }

        void Room::addTrap(Trap *trap) {
            mTraps.push_back(trap);
        }

        std::vector<Mob*> &Room::mobs() {
            return mMobs;
        }

        void Room::addMob(Mob *mob) {
            mob->setRoom(this);
            mMobs.push_back(mob);
        }

        void Room::removeMob(Mob *mob) {
            mMobs.erase(std::remove(mMobs.begin(), mMobs.end(), mob), mMobs.end());
        }

        char Room::repr() const {
            if(!isVisited())
                return '.';

            // ladder room?
            Ladder *ladder = dynamic_cast<Ladder*>(mInventory.findItem("Ladder"));
            if(ladder) {
                return ladder->direction() == Ladder::UP ? 'H' : 'L';
            }

            // start room?
            Item *breadcrumb = mInventory.findItem("Breadcrumb");
            if(breadcrumb)
                return 'S';

            // endboss here?
            for(Mob *mob : mMobs) {
                if(mob->level() >= 11)
                    return 'E';
            }

            // normal room?
            return 'N';
        }

        int Room::weight() {
            int weight = 0;

            for(dc::model::Mob *mob : mobs()) {
                weight += mob->level();
            }

            return weight;
        }

        std::ostream &operator<<(std::ostream &output, const Room &c) {
            output << std::fixed << std::setprecision(15) << "R" << "\t" << c.mLighted << "\t" << c.position() << "\t;\t";

            // save traps
            for(dc::model::Trap *trap : c.mTraps) {
                output << *trap << "\t";
            }
            output << ";\t";

            // save mobs
            for(dc::model::Mob *mob : c.mMobs) {
                output << *mob << "\t";
            }
            output << ";\t";

            return output;
        }

        std::istream &operator>>(std::istream &input, Room &c) {
            input >> c.mVisited;

            return input;
        }

        bool Room::isDirty() const {
            return mIsDirty;
        }

        bool Room::isLighted() const {
            return mLighted;
        }

        void Room::lighRoom() {
            mLighted = true;
        }
        
        void Room::tickMobs(dc::model::Character &character) {
            for(dc::model::Mob* mob : mMobs) {
                if(mob->isDead()) {
                    removeMob(mob);
                    delete mob;
                } else {
                    mob->tick(character);
                }
            }
        }
    }
}
