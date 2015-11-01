#ifndef DUNGEONCRAWLER_GRANATE_H
#define DUNGEONCRAWLER_GRANATE_H

#include "Floor.h"
#include "Room.h"
#include "Item.h"

namespace dc {
    namespace model {
        class Grenade : public Item {
        public:
            Grenade();

            virtual void use(Character &character) override;


            virtual Item *clone() const;

            bool explode(Floor *pFloor, Room *pRoom);
        };
    }
}

#endif //DUNGEONCRAWLER_GRANATE_H
