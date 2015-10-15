#ifndef DUNGEONCRAWLER_ROOM_H
#define DUNGEONCRAWLER_ROOM_H

#include <vector>
#include <string>
#include "Point.h"

namespace dc {
    namespace model {
        class Passage;
        class Trap;
        class Floor;
    }
}

namespace dc {
    namespace model {
        class Room {
        public:
            Room(std::string description);
            Room(Point position, std::string description);
            Room(Point position, std::string description, bool visited);
            Room(Point position, std::string description, bool visited, std::vector<Trap*> traps);
            ~Room();

            void setPosition(Point point);
            const Point &position() const;

            std::string description() const;

			std::vector<Passage*> adjacantPassages() const;
            Passage *north() const;
            Passage *east() const;
            Passage *south() const;
            Passage *west() const;

            void setNorth(Passage *passage);
            void setEast(Passage *passage);
            void setSouth(Passage *passage);
            void setWest(Passage *passage);

			bool isVisited() const;
            void setVisited(bool visited);

            Floor *floor() const;
            void setFloor(Floor* floor);

            std::vector<Trap*> traps() const;
            void addTrap(Trap* trap);

        private:
            Point mPosition;
            std::string mDescription;
            bool mVisited;

            Passage *mNorth;
            Passage *mEast;
            Passage *mSouth;
            Passage *mWest;

            Floor *mFloor;

            std::vector<Trap*> mTraps;
        };
    }
}


#endif //DUNGEONCRAWLER_ROOM_H
