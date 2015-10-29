#include <iostream>
#include <list>
#include "util/DijkstraPathfinder.h"
#include "Compass.h"
#include "Character.h"
#include "Floor.h"
#include "Room.h"

namespace dc {
    namespace model {
        Compass::Compass() :
            Item("Compass", "This compass is so smart, it can make bends!") {

        }

        void Compass::use(Character &character) {
            dc::model::Room *startRoom = character.room();
            dc::model::Floor *floor = startRoom->floor();
            dc::model::Room *endRoom = &floor->exitRoom();

            std::list<dc::model::Room*> path = DijkstraPathfinder::findPath(*floor, *startRoom, *endRoom);

            std::cout << "Found ye path!" << std::endl;
        }
    }
}