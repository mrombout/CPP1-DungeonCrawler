#include "Player.h"

namespace dc {
    namespace model {
        Player::Player(Room *room, Inventory *inventory) :
            Character(room),
            mInventory(inventory) {

        }

        Inventory &dc::model::Player::inventory() const {
            return *mInventory;
        }
    }
}
