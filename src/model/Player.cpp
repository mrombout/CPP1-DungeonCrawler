#include <math.h>
#include "Player.h"

namespace dc {
    namespace model {
        Player::Player(Room *room) :
            Character(room) {
            room->setVisited(true);
        }

        void Player::setRoom(Room *room) {
            Character::setRoom(room);
            room->setVisited(true);
        }

        unsigned int Player::level() const {
            return 1 + floor(mExperience / 5);
        }

        unsigned int Player::attack() const {
            return 1 + ceil(level() / 2);
        }
    }
}
