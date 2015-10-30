#include "ExperiencePotion.h"
#include "util/console.h"

namespace dc {
    namespace model {
        ExperiencePotion::ExperiencePotion(const std::string &name, const std::string &description, int effect) :
                Potion(name, description, effect) {

        }

        void ExperiencePotion::consume(Character &character) {
            character.increaseExperience(effect());
            std::cout << csl::color(csl::GREEN) << "You have earned " << effect() << " experience points." << std::endl;
        }

        Item *ExperiencePotion::clone() const {
            return new ExperiencePotion(*this);
        }
    }
}
