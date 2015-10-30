#include "Potion.h"

namespace dc {
    namespace model {
        Potion::Potion(unsigned int id, std::string name, std::string description, int effect) :
                Consumable(id, name, description),
                mEffect(effect) {

        }

        int Potion::effect() const {
            return mEffect;
        }
    }
}