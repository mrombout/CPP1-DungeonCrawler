#include <iomanip>
#include <iostream>
#include "Dungeon.h"
#include "Floor.h"

namespace dc {
    namespace model {
        Dungeon::Dungeon(int seed, const std::string &name, std::vector<Floor *> floors) :
                mName(name),
                mFloors(floors) {

        }

        Dungeon::~Dungeon() {
            for(std::vector<model::Floor*>::iterator it = mFloors.begin(); it != mFloors.end(); ++it) {
                delete *it;
            }
        }

        Floor &Dungeon::floor(int level) const {
            return *mFloors[level];
        }

        std::ostream &operator<<(std::ostream &output, const Dungeon &c) {
            output << std::fixed << std::setprecision(15);

            for(dc::model::Floor *floor : c.mFloors)
                output << *floor;

            return output;
        }

        std::istream &operator>>(std::istream &input, Dungeon &c) {
            return input;
        }
    }
}