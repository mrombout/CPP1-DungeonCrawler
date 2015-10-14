#include "RoomGenerator.h"

dc::model::Room *RoomGenerator::generate(unsigned int seed) {
    return new dc::model::Room(Point(0, 0), "Some Random description");
}
