#include "Ladder.h"
#include "Room.h"

namespace dc {
    namespace model {
        Ladder::Ladder(Room &toRoom) :
                Fixture("Ladder", "Just a ladder leading to " + toRoom.name() + "."),
                mToRoom(toRoom) {

        }

        void Ladder::use(Character &character) {
            character.setRoom(&mToRoom);
        }
    }
}
