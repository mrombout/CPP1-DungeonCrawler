#ifndef DUNGEONCRAWLER_INVENTORY_H
#define DUNGEONCRAWLER_INVENTORY_H

#include <vector>
#include "Item.h"

namespace dc {
    namespace model {
        class Inventory {
        public:
            Inventory(std::vector<Item*> items);
            ~Inventory();
            std::string description() const;
        private:
            std::vector<Item*> mItems;
        };
    }
}


#endif //DUNGEONCRAWLER_INVENTORY_H
