//
// Created by Mike Rombout on 5/10/2015.
//

#include "Inventory.h"
namespace dc {
    namespace model {
        std::string Inventory::description() const {
            std::string listing ("");

            for(std::vector<int>::size_type i = 0; i != mItems.size(); ++i) {
                listing += "\r\n" + mItems[i].description();
            }
        }
    }
}