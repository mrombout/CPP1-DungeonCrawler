#ifndef DUNGEONCRAWLER_ROOM_H
#define DUNGEONCRAWLER_ROOM_H

#include <vector>
#include <string>

namespace dc {
    namespace model {
        class Passage;
        class Trap;
    }
}

namespace dc {
    namespace model {
        class Room {
        private:
            std::string mDescription;
            bool mVisited;

            Passage &mNorth;
            Passage &mEast;
            Passage &mSouth;
            Passage &mWest;

            std::vector<Trap*> mTraps;
        };
    }
}


#endif //DUNGEONCRAWLER_ROOM_H