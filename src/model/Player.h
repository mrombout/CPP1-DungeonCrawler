#ifndef DUNGEONCRAWLER_PLAYER_H
#define DUNGEONCRAWLER_PLAYER_H

#include "Inventory.h"
#include "Room.h"
#include "Character.h"

namespace dc {
    namespace model {
        class Player : public Character {
        public:
            Player(Room *room);

            virtual void setRoom(Room *room) override;
            virtual unsigned int level() const override;
            virtual unsigned int attack() const override;
        };
    }
}

#endif //DUNGEONCRAWLER_PLAYER_H
