#include "Consumable.h"
#include "Inventory.h"
#include "Character.h"

namespace dc {
    namespace model {
        Consumable::Consumable(unsigned int id, std::string name, std::string description) :
                Item(id, name, description) {

        }

        Consumable::~Consumable() {

        }

        void Consumable::use(Character &character) {
            consume(character);

            character.inventory().removeItem(*this);
            delete this;
        }
    }
}
