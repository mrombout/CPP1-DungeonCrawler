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
        public:
            Floor(int level, std::vector<Room*> rooms);
            ~Floor();

            int level() const;

        private:
            int mLevel;

            std::vector<Room*> mRooms;
        };
    }
}

#endif //DUNGEONCRAWLER_FLOOR_H
