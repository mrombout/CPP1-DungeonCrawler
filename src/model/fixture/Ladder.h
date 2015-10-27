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
        class Ladder : public Fixture {
        public:
            enum Direction {
                UP,
                DOWN
            };

            Ladder(Direction direction, Room &toRoom);

            virtual void use(Character &character) override;

            Direction direction() const;

        private:
            Direction mDirection;
            Room &mToRoom;
        };
    }
}


#endif //DUNGEONCRAWLER_LADDER_H
