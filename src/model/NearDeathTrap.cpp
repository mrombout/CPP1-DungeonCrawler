#include <iostream>
#include "NearDeathTrap.h"
#include "Player.h"

void dc::model::NearDeathTrap::onSpring(dc::model::Player &player) {
    std::cout << "A giant ball of spikes comes hurling towards you. You are just quick enough to jump aside and avoid definite death.";
    std::cout << "On your way up you hit your head on an inconveniently placed lantern, it hurts.\n";

    player.setHealth(1);

    std::cout << "You health has been decreased to 1." << std::endl;
}

const std::string dc::model::NearDeathTrap::name() {
    return "intriguing contraption";
}
