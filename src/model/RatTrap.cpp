#include <iostream>
#include "RatTrap.h"

namespace dc {
    namespace model {
        const std::string RatTrap::ID = "RATTRAP";

        void RatTrap::onSpring(Player &player) {
            std::cout << "Cling! A small clamp grabs your foot. It's too small and weak to actually hurt, but you are immensely annoyed.";
            std::cout << "Nothing happens." << std::endl;
        }

        const std::string RatTrap::name() {
            return "rat trap";
        }

        const std::string RatTrap::id() const {
            return ID;
        }
    }
}
