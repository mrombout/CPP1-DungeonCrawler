#ifndef DUNGEONCRAWLER_PLAYER_H
#define DUNGEONCRAWLER_PLAYER_H

#include "Inventory.h"
#include "Room.h"

namespace dc {
    namespace model {
        class Player {
        public:
            Player(Room &room);

            Room &room() const;

        private:
            Inventory *mInventory;
            Room &mRoom;
        };
    }
}


#endif //DUNGEONCRAWLER_PLAYER_H
