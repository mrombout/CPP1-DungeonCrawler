#ifndef DUNGEONCRAWLER_FLOOR_H
#define DUNGEONCRAWLER_FLOOR_H

#include <iostream>
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

            friend std::ostream &operator<<(std::ostream &output, const Floor &f);
            friend std::istream &operator>>(std::istream &input, Floor &f);

        private:
            int mLevel;

            Room* mStartRoom;
            Room* mExitRoom;
            std::vector<std::vector<Room*>> mRooms;
        };
    }
}

#endif //DUNGEONCRAWLER_FLOOR_H
