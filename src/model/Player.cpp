#include "Player.h"

namespace dc {
    namespace model {
        Player::Player(Room &room, Inventory *inventory) :
            Character(),
            mRoom(room), mInventory(inventory) {

        }

        Room &dc::model::Player::room() const {
            return mRoom;
        }

        Inventory &dc::model::Player::inventory() const {
            return *mInventory;
        }
    }
}
