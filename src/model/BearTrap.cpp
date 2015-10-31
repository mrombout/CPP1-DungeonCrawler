#include <iostream>
#include "BearTrap.h"
#include "Player.h"

namespace dc {
    namespace model {
        const std::string BearTrap::ID = "BEARTRAP";

        void BearTrap::onSpring(Player &player) {
            std::cout << "\a A bear trap suddenly grabs ahold of your leg! After a while of fiddling you manage to free yourself unharmed. But your boots are slightly damaged, you are heartbroken. Your mom just got those for you.\n";
            player.decreaseHealth(5);

            std::cout << "Your health decreased by 5." << std::endl;
        }

        const std::string BearTrap::name() {
            return "bear trap";
        }

        const std::string BearTrap::id() const {
            return ID;
        }

    }
}
