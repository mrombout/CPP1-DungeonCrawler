#include "Ladder.h"
#include "Room.h"

namespace dc {
    namespace model {
        Ladder::Ladder(Ladder::Direction direction, Room &toRoom) :
            Fixture("Ladder", "Just a ladder leading to " + toRoom.name() + "."),
            mDirection(direction),
            mToRoom(toRoom) {

        }

        void Ladder::use(Character &character) {
            character.setRoom(&mToRoom);
        }

        Ladder::Direction Ladder::direction() const {
            return mDirection;
        }

        Item *Ladder::clone() const {
            return new Ladder(*this);
        }
    }
}
