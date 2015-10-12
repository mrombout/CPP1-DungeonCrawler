#ifndef DUNGEONCRAWLER_INVENTORY_H
#define DUNGEONCRAWLER_INVENTORY_H

#include <vector>
#include "Item.h"

namespace dc {
    namespace model {
        class Inventory {
        public:
            std::string description() const;
        private:
            std::vector<Item> mItems;
        };
    }
}


#endif //DUNGEONCRAWLER_INVENTORY_H
