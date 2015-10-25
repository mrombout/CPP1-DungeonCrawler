#ifndef DUNGEONCRAWLER_EQUIPABLE_H
#define DUNGEONCRAWLER_EQUIPABLE_H

#include "Item.h"

namespace dc {
    namespace model {
        class Equipable : public Item {
        public:
            Equipable();
            virtual ~Equipable() = 0;
        };
    }
}

#endif //DUNGEONCRAWLER_EQUIPABLE_H
