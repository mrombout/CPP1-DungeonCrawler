#include "Consumable.h"

namespace dc {
    namespace model {
        Consumable::Consumable(std::string name, std::string description) :
                Item(name, description) {

        }

        Consumable::~Consumable() {

        }

        void Consumable::use(Character &character) {
            consume(character);

            character.inventory().removeItem(*this);
        }
    }
}
