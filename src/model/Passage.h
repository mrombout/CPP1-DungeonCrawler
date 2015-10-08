#ifndef DUNGEONCRAWLER_PASSAGE_H
#define DUNGEONCRAWLER_PASSAGE_H

namespace dc {
    namespace model {
        class Room;
    }
}

namespace dc {
    namespace model {
        class Passage {
        public:
            Passage(Room &sideA, Room &sideB);

        private:
            Room &mSideA;
            Room &mSideB;
        };
    }
}


#endif //DUNGEONCRAWLER_PASSAGE_H
