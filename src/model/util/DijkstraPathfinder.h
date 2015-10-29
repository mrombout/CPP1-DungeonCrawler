#ifndef DUNGEONCRAWLER_DIJKSTRAPATHFINDER_H
#define DUNGEONCRAWLER_DIJKSTRAPATHFINDER_H

namespace dc {
    namespace model {
        class Floor;
        class Room;
        class Passage;
    }
}

class DijkstraPathfinder {
public:
    static std::list<dc::model::Passage*> findPath(dc::model::Floor &floor, dc::model::Room &startRoom, dc::model::Room &endRoom);
};

#endif //DUNGEONCRAWLER_DIJKSTRAPATHFINDER_H
