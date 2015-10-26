#ifndef DUNGEONCRAWLER_PLAYER_H
#define DUNGEONCRAWLER_PLAYER_H

#include "Inventory.h"
#include "Room.h"
#include "Character.h"

namespace dc {
    namespace model {
        class Player : public Character {
        public:
            Player(Room *room, Inventory *inventory);

            Inventory &inventory() const;

        private:
            Inventory *mInventory;
        };
    }
}

#endif //DUNGEONCRAWLER_PLAYER_H
