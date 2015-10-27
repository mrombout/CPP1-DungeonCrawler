#ifndef DUNGEONCRAWLER_CONSUMABLE_H
#define DUNGEONCRAWLER_CONSUMABLE_H

#include "item/Item.h"

namespace dc {
    namespace model {
        class Consumable : public Item {
        public:
            Consumable(std::string name, std::string description);
            virtual ~Consumable() = 0;
        };
    }
}

#endif //DUNGEONCRAWLER_CONSUMABLE_H
