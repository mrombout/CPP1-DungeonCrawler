#include <algorithm>
#include "Inventory.h"
#include "item/Item.h"

namespace dc {
    namespace model {
        Inventory::Inventory() {

        }

        Inventory::Inventory(std::vector<Item*> items) :
                mItems(items) {

        }

        Inventory::~Inventory() {
            for(std::vector<model::Item*>::iterator it = mItems.begin(); it != mItems.end(); ++it) {
                delete *it;
            }
        }

        Item *Inventory::findItem(const std::string &itemName) const {
            for(Item *item : mItems) {
                if(item->partialMatch(itemName)) {
                    return item;
                }
            }

            return nullptr;
        }

        void Inventory::add(Item &item) {
            mItems.push_back(&item);
        }

        std::string Inventory::description() const {
            std::string listing ("");

            if (mItems.empty()) {
                listing += "\r\nEmpty inventory";
            } else {
                for (std::vector<int>::size_type i = 0; i != mItems.size(); ++i) {
                    listing += "\r\n" + mItems[i]->description();
                }
            }

            return listing;
        }

        const std::vector<Item *> &Inventory::items() const {
            return mItems;
        }

        void Inventory::addItem(Item &item) {
            addItem(&item);
        }

        void Inventory::addItem(Item *item) {
            mItems.push_back(item);
        }

        bool Inventory::removeItem(Item &item) {
            mItems.erase(std::remove(mItems.begin(), mItems.end(), &item), mItems.end());
        }
    }
}