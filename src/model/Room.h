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
        public:
            Room(std::string description);
            Room(std::string description, bool visited);
            Room(std::string description, bool visited, std::vector<Trap*> traps);
            ~Room();

            std::string description() const;

            Passage *north() const;
            Passage *east() const;
            Passage *south() const;
            Passage *west() const;

            void setNorth(Passage *passage);
            void setEast(Passage *passage);
            void setSouth(Passage *passage);
            void setWest(Passage *passage);

            void setVisited(bool visited);

        private:
            std::string mDescription;
            bool mVisited;

            Passage *mNorth;
            Passage *mEast;
            Passage *mSouth;
            Passage *mWest;

            std::vector<Trap*> mTraps;
        };
    }
}


#endif //DUNGEONCRAWLER_ROOM_H
