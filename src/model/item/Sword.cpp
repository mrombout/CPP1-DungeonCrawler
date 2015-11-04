#include "Sword.h"

namespace dc {
    namespace model {
        Sword::Sword(unsigned int id, std::string name, std::string description, int damage) : Equipable(id, name, description, damage) { }
        Sword::~Sword() {

        }

        Item *Sword::clone() const {
            return new Sword(*this);
        }
    }
}