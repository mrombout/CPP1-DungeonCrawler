#include "util/console.h"
#include "HealthPotion.h"
#include "Character.h"

namespace dc {
    namespace model {
        HealthPotion::HealthPotion(unsigned int id, const std::string &name, const std::string &description, int effect) :
                Potion(id, name, description, effect) {

        }

        void HealthPotion::consume(Character &character) {
            character.setHealth(character.health() + effect());
            std::cout << csl::color(csl::GREEN) << "You have been healed " << effect() << " health points." << std::endl;
        }

        Item *HealthPotion::clone() const {
            return new HealthPotion(*this);
        }
    }
}
