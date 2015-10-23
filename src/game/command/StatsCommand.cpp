#include <iostream>
#include "StatsCommand.h"

void StatsCommand::execute(dc::engine::CommandParameters &parameters) const {
    std::cout << "You reflect on what you have learned: \n\n";
    dc::model::Player &player = parameters.player();

    std::cout << "Level: " << player.level() << "\n";
    std::cout << "Experience: " << player.experience() << "\n\n";
    std::cout << "----------------\n\n";
    std::cout << "Health: " << player.health() << "\n";
    std::cout << "Attack: " << player.attack() << "\n";
    std::cout << "Defence: " << player.defence() << "\n";
    std::cout << "Perception: " << player.perception() << "\n\n";
}
