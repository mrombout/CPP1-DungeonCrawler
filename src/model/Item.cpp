//
// Created by Mike Rombout on 5/10/2015.
//

#include "Item.h"
namespace dc {
    namespace model {

        Item::Item(std::string description) : mDescription(description) {
        }

        std::string Item::description() const {
            return mDescription;
        }
    }
}