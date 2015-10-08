#include "Dungeon.h"
#include "Floor.h"

namespace dc {
    namespace model {
        Dungeon::Dungeon(int seed, std::string &name, std::vector<Floor *> floors) :
                mName(name),
                mFloors(floors) {

        }

        Dungeon::~Dungeon() {
            for(std::vector<model::Floor*>::iterator it = mFloors.begin(); it != mFloors.end(); ++it) {
                delete *it;
            }
        }
    }
}