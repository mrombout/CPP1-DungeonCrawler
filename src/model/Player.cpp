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
    }
}
