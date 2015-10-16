#include <iostream>
#include "BearTrap.h"
#include "Player.h"

void dc::model::BearTrap::spring(dc::model::Player &player) {
    std::cout << "\a A bear trap suddenly grabs ahold of your leg! After a while of fiddling you manage to free yourself unharmed. But your boots are slightly damaged, you are heartbroken. Your mom just got those for you." << std::endl;
    player.decreaseHealth(5);
}
