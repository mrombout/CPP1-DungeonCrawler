#include <cstring>
#include <iostream>
#include "Item.h"
#include "Player.h"
#include "util/console.h"
#include "util/String.h"

namespace dc {
    namespace model {
        Item::Item(unsigned int id, std::string name, std::string description) :
                mId(id),
                mName(name),
                mDescription(description) {

        }

        unsigned int Item::id() const {
            return mId;
        }

        std::string Item::name() const {
            return mName;
        }

        std::string Item::description() const {
            return mDescription;
        }

        void Item::pickUp(Player &player) {
            if(!player.room()->inventory().removeItem(*this)) {
                std::cout << "You can't pick that up!" << std::endl;
            }

            std::cout << "You pick up the " << csl::color(csl::BLUE) << mName << "." << std::endl;
            player.inventory().add(*this);
        }

        void Item::use(Character &character) {
            std::cout << "You try to use the " << mName << ". You hurt your finger as you fail tremendously." << std::endl;
        }

        bool Item::partialMatch(const std::string &string) const {
            return String::toLower(mName).find(String::toLower(string)) != std::string::npos;
        }
    }
}