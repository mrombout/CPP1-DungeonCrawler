#include "Sword.h"

namespace dc {
    namespace model {
        Sword::Sword(std::string name, std::string description, int damage) : Equipable(name, description, damage) { }
        Sword::~Sword() {

        }

        Item *Sword::clone() const {
            return new Sword(*this);
        }
    }
}