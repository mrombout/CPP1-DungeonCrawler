#include <iostream>
#include "BearTrap.h"
#include "Player.h"

namespace dc {
    namespace model {
        const std::string BearTrap::ID = "BEARTRAP";

        BearTrap::BearTrap(const int damage) :
            mDamage(damage) {

        }

        void BearTrap::onSpring(Player &player) {
            std::cout << "A bear trap suddenly grabs ahold of your leg! After a while of fiddling you manage to free yourself unharmed. But your boots are slightly damaged, you are heartbroken. Your mom just got those for you.\n";
            player.decreaseHealth(mDamage);

            std::cout << "Your health decreased by " << mDamage << "." << std::endl;
        }

        const std::string BearTrap::name() {
            return "bear trap";
        }

        const std::string BearTrap::id() const {
            return ID;
        }
    }
}
