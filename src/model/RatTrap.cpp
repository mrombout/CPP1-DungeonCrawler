#include <iostream>
#include "RatTrap.h"

void dc::model::RatTrap::onSpring(dc::model::Player &player) {
    std::cout << "Cling! A small clamp grabs your foot. It's too small and weak to actually hurt, but you are immensely annoyed.";
    std::cout << "Nothing happens." << std::endl;
}

const std::string dc::model::RatTrap::name() {
    return "rat trap";
}
