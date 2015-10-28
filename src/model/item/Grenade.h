#ifndef DUNGEONCRAWLER_GRANATE_H
#define DUNGEONCRAWLER_GRANATE_H

#include "Item.h"

namespace dc {
    namespace model {
        class Grenade : public Item {
        public:
            Grenade();

            virtual void use(Character &character) override;
        };
    }
}

#endif //DUNGEONCRAWLER_GRANATE_H
