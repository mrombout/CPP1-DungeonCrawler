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
        private:
            Room &mSideA;
            Room &mSideB;
        };
    }
}


#endif //DUNGEONCRAWLER_PASSAGE_H
