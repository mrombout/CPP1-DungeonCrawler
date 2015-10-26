#ifndef DUNGEONCRAWLER_LADDER_H
#define DUNGEONCRAWLER_LADDER_H

#include "Fixture.h"

namespace dc {
    namespace model {
        class Room;
    }
}

namespace dc {
    namespace model {
        class Ladder : Fixture {
        public:
            Ladder(Room &toRoom);

            virtual void use(Character &character) override;

        private:
            Room &mToRoom;
        };
    }
}


#endif //DUNGEONCRAWLER_LADDER_H
