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
        class Dungeon {
        public:
            Dungeon(int seed, const std::string &name, std::vector<Floor*> floors);
            ~Dungeon();

            Floor &floor(int level) const;

            friend std::ostream &operator<<(std::ostream &output, const Dungeon &d);
            friend std::istream &operator>>(std::istream &input, Dungeon &d);

        private:
            std::string mName;
            int mSeed;

            std::vector<Floor*> mFloors;
        };
    }
}


#endif //DUNGEONCRAWLER_DUNGEON_H
