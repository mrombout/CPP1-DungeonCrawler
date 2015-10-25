#ifndef DUNGEONCRAWLER_PLAYER_H
#define DUNGEONCRAWLER_PLAYER_H

#include "Inventory.h"
#include "Room.h"
#include "Character.h"

namespace dc {
    namespace model {
        class Player : public Character {
        public:
            Player(Room &room, Inventory *inventory);

            Room &room() const;
            Inventory &inventory() const;
            void setRoom(Room &room);

        private:
            Inventory *mInventory;
            Room *mRoom;
        };
    }
}

#endif //DUNGEONCRAWLER_PLAYER_H
