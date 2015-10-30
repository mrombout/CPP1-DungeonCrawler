#ifndef DUNGEONCRAWLER_TALISMAN_H
#define DUNGEONCRAWLER_TALISMAN_H

#include <map>
#include "Item.h"

namespace dc {
    namespace model {
        class Character;
    }
}

namespace dc {
    namespace model {
        class Talisman : public Item {
        public:
            Talisman();

            virtual void use(Character& character) override;
            virtual Item *clone() const;

            bool isLadderUp(std::map<Room*, int> &distances, Room &room);
        };
    }
}

#endif //DUNGEONCRAWLER_TALISMAN_H
