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
            Floor(int level, std::vector<std::vector<Room*>> rooms, Room* startRoom, Room* exitRoom);
            ~Floor();

            int level() const;

            unsigned int width() const;
            unsigned int height() const;

            Room &startRoom() const;
            Room &exitRoom() const;

            const std::vector<std::vector<Room*>> &rooms() const;

        private:
            int mLevel;

            Room* mStartRoom;
            Room* mExitRoom;
            std::vector<std::vector<Room*>> mRooms;
        };
    }
}

#endif //DUNGEONCRAWLER_FLOOR_H
