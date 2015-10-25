#ifndef DUNGEONCRAWLER_CONSUMABLE_H
#define DUNGEONCRAWLER_CONSUMABLE_H

#include "Item.h"

namespace dc {
    namespace model {
        class Consumable : public Item {
        public:
            Consumable();
            virtual ~Consumable() = 0;
        };
    }
}

#endif //DUNGEONCRAWLER_CONSUMABLE_H
