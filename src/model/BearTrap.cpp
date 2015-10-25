#include <iostream>
#include "BearTrap.h"
#include "Player.h"

void dc::model::BearTrap::onSpring(dc::model::Player &player) {
    std::cout << "\a A bear trap suddenly grabs ahold of your leg! After a while of fiddling you manage to free yourself unharmed. But your boots are slightly damaged, you are heartbroken. Your mom just got those for you.\n";
    player.decreaseHealth(5);

    std::cout << "Your health decreased by 5." << std::endl;
}

const std::string dc::model::BearTrap::name() {
    return "bear trap";
}
