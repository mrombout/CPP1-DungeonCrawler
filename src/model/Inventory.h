#ifndef DUNGEONCRAWLER_INVENTORY_H
#define DUNGEONCRAWLER_INVENTORY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "item/Item.h"

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

            const std::vector<Item*> &items() const;
            void addItem(Item &item);
            void addItem(Item *item);
            bool removeItem(Item &item);

            friend std::ostream &operator<<(std::ostream &output, const Inventory &i) {
                output << std::fixed << std::setprecision(15);

                for(Item *item : i.mItems) {
                    if(item->id() != 0)
                        output << item->id() << "\t";
                }

                return output;
            }

        private:
            std::vector<Item*> mItems;
        };
    }
}


#endif //DUNGEONCRAWLER_INVENTORY_H
