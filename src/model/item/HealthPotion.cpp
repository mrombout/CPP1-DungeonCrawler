#include "util/console.h"
#include "HealthPotion.h"

namespace dc {
    namespace model {
        HealthPotion::HealthPotion(const std::string &name, const std::string &description, int effect) :
                Potion(name, description, effect) {

        }

        void HealthPotion::consume(Character &character) {
            character.setHealth(character.health() + effect());
            std::cout << csl::color(csl::GREEN) << "You have been healed " << effect() << " health points." << std::endl;
        }
    }
}
