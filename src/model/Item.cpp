//
// Created by Mike Rombout on 5/10/2015.
//

#include "Item.h"
namespace dc {
    namespace model {

        Item::Item(std::string name, std::string description) :
                mName(name),
                mDescription(description) {

        }

        std::string Item::name() const {
            return mName;
        }

        std::string Item::description() const {
            return mDescription;
        }
    }
}