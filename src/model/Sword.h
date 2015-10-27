#ifndef DUNGEONCRAWLER_SWORD_H
#define DUNGEONCRAWLER_SWORD_H

#include <string>
#include "item/Item.h"

namespace dc {
    namespace model {
        class Sword : public Item {

        public:
            Sword(const std::string &name, const std::string &description) : Item(name, description) { }

            virtual ~Sword();
        };
    }
}

#endif //DUNGEONCRAWLER_SWORD_H
