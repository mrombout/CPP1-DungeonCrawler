#ifndef DUNGEONCRAWLER_ITEMFACTORY_H
#define DUNGEONCRAWLER_ITEMFACTORY_H

#include <fixture/Ladder.h>

namespace dc {
    namespace model {
        class Room;
        class Fixture;
    }
}

namespace dc {
    namespace game {
        class ItemFactory {
        public:
            static dc::model::Ladder* createLadder(dc::model::Room &otherRoom);
        };
    }
}

#endif //DUNGEONCRAWLER_ITEMFACTORY_H
