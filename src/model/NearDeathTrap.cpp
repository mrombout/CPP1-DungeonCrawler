#include <iostream>
#include "NearDeathTrap.h"
#include "Player.h"

void dc::model::NearDeathTrap::spring(dc::model::Player &player) {
    std::cout << "TODO: Some text describing the NearDeathTrap" << std::endl;
    player.setHealth(1);
}
