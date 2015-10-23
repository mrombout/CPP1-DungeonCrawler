//
// Created by Mike Rombout on 5/10/2015.
//

#include "Inventory.h"
namespace dc {
    namespace model {
        Inventory::Inventory(std::vector<Item*> items) :
                mItems(items) {

        }

        Inventory::~Inventory() {
            for(std::vector<model::Item*>::iterator it = mItems.begin(); it != mItems.end(); ++it) {
                delete *it;
            }
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

        Item *Inventory::findItem(const std::string &itemName) const {
            for(Item *item : mItems) {
                if(item->partialMatch(itemName)) {
                    return item;
                }
            }

            return nullptr;
        }
    }
}