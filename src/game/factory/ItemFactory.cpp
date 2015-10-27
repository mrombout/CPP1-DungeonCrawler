#include "ItemFactory.h"
#include "fixture/Ladder.h"

namespace dc {
    namespace game {
        dc::model::Ladder *ItemFactory::createLadder(dc::model::Room &otherRoom) {
            dc::model::Ladder *ladder = new dc::model::Ladder(otherRoom);
            return ladder;
        }
    }
}
