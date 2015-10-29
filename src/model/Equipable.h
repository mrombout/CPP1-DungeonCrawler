#ifndef DUNGEONCRAWLER_EQUIPABLE_H
#define DUNGEONCRAWLER_EQUIPABLE_H

#include "item/Item.h"

namespace dc {
    namespace model {
        class Equipable : public Item {
        public:
            Equipable(std::string name, std::string description, int damage);
            virtual ~Equipable();
        };
    }
}

#endif //DUNGEONCRAWLER_EQUIPABLE_H
