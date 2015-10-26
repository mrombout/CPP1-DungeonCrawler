#ifndef DUNGEONCRAWLER_INVENTORY_H
#define DUNGEONCRAWLER_INVENTORY_H

#include <string>
#include <vector>

namespace dc {
    namespace model {
        class Item;
    }
}

namespace dc {
    namespace model {
        class Inventory {
        public:
            Inventory();
            Inventory(std::vector<Item*> items);
            ~Inventory();

            Item *findItem(const std::string &itemName) const;

            void add(Item &item);

            std::string description() const;

            const std::vector<Item*> &items() const;
            void addItem(Item &item);
            bool removeItem(Item &item);
        private:
            std::vector<Item*> mItems;
        };
    }
}


#endif //DUNGEONCRAWLER_INVENTORY_H
