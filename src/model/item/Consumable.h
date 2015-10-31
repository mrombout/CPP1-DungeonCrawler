#ifndef DUNGEONCRAWLER_CONSUMABLE_H
#define DUNGEONCRAWLER_CONSUMABLE_H

#include "item/Item.h"

namespace dc {
    namespace model {
        class Consumable : public Item {
        public:
            Consumable(unsigned int id, std::string name, std::string description);
            virtual ~Consumable();

            virtual void use(Character &character) override;
            virtual void consume(Character &character) = 0;
        };
    }
}

#endif //DUNGEONCRAWLER_CONSUMABLE_H
