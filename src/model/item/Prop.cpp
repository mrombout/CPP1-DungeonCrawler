#include "Prop.h"

namespace dc {
    namespace model {
        void Prop::pickUp(Player &player) {
            // nop
        }

        void Prop::use(Character &character) {
            // nop
        }

        Item *Prop::clone() const {
            return new Prop(*this);
        }
    }
}
