#include "Player.h"

namespace dc {
    namespace model {
        Player::Player(Room &room) :
            mRoom(room) {

        }

        Room &dc::model::Player::room() const {
            return mRoom;
        }

        Inventory &dc::model::Player::inventory() const {
            return (Inventory &) mInventory;
        }
    }
}
