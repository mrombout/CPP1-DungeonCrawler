#include "Potion.h"

namespace dc {
    namespace model {
        Potion::Potion(std::string name, std::string description, int effect) :
                Consumable(name, description),
                mEffect(effect) {

        }

        int Potion::effect() const {
            return mEffect;
        }
    }
}