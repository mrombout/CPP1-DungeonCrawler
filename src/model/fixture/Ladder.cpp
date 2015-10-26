#include "Ladder.h"

namespace dc {
    namespace model {
        Ladder::Ladder(Room &toRoom) :
                Fixture("Ladder", "Just a ladder."),
                mToRoom(toRoom) {

        }

        void Ladder::use(Character &character) {
            character.setRoom(&mToRoom);
        }
    }
}
