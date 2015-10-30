#ifndef DUNGEONCRAWLER_DUNGEONGENERATOR_H
#define DUNGEONCRAWLER_DUNGEONGENERATOR_H

#include <string>
#include "MobGenerator.h"

namespace dc {
    namespace model {
        class Dungeon;
        class Floor;
    }
}

namespace dc {
    namespace game {
        class FloorGenerator;
    }
}

namespace dc {
    namespace game {
        /**
         * Generates a new dungeon consisting of a random number of floors.
         */
        class DungeonGenerator {
        public:
            DungeonGenerator(FloorGenerator &floorGenerator, MobGenerator &mobGenerator);

            dc::model::Dungeon *generate(unsigned int seed, unsigned int width, unsigned int height) const;

        private:
            std::string generateDungeonName() const;
            dc::model::Floor *generateDungeonFloor(int level, unsigned int width, unsigned int height) const;

            FloorGenerator &mFloorGenerator;
            MobGenerator &mMobGenerator;
        };
    }
}

#endif //DUNGEONCRAWLER_DUNGEONGENERATOR_H
