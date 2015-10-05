#ifndef DUNGEONCRAWLER_DUNGEON_H
#define DUNGEONCRAWLER_DUNGEON_H

#include <vector>
#include <string>

namespace dc {
    namespace model {
        class Floor;
    }
}

namespace dc {
    namespace model {
        /**
         * NOTE: Random thought, instead of persisting the entire dungeon to a text file. How about saving only the
         * dynamic data and regenerate the same dungeon from the seed! E.g. we'd save that monster X is in room 3.
         */
        class Dungeon {
        private:
            std::string mName;
            int mSeed;

            std::vector<Floor*> mFloors;
        };
    }
}


#endif //DUNGEONCRAWLER_DUNGEON_H
