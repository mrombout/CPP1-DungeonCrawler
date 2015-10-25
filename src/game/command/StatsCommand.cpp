#include <iostream>
#include "StatsCommand.h"
#include "Player.h"

StatsCommand::StatsCommand(dc::model::Player &player) :
    mPlayer(player) {

}

void StatsCommand::execute() const {
    std::cout << "You reflect on what you have learned: \n\n";

    std::cout << "Level: " << mPlayer.level() << "\n";
    std::cout << "Experience: " << mPlayer.experience() << "\n\n";
    std::cout << "----------------\n\n";
    std::cout << "Health: " << mPlayer.health() << "/" << mPlayer.maxHealth() << "\n";
    std::cout << "Attack: " << mPlayer.attack() << "\n";
    std::cout << "Defence: " << mPlayer.defence() << "\n";
    std::cout << "Perception: " << mPlayer.perception() << "\n\n";
}
