#ifndef DUNGEONCRAWLER_DIJKSTRAPATHFINDER_H
#define DUNGEONCRAWLER_DIJKSTRAPATHFINDER_H

#include <Room.h>

namespace dc {
    namespace model {
        class Floor;
        class Room;
    }
}

class DijkstraPathfinder {
public:
    static std::list<dc::model::Room*> findPath(dc::model::Floor &floor, dc::model::Room &startRoom, dc::model::Room &endRoom);
};

#endif //DUNGEONCRAWLER_DIJKSTRAPATHFINDER_H
