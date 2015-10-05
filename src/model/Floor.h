#ifndef DUNGEONCRAWLER_FLOOR_H
#define DUNGEONCRAWLER_FLOOR_H

#include <vector>

namespace dc {
    namespace model {
        class Room;
    }
}

namespace dc {
    namespace model {
        class Floor {
        private:
            int mLevel;

            std::vector<Room*> mRooms;
        };
    }
}

#endif //DUNGEONCRAWLER_FLOOR_H
