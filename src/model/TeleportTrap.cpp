#include <iostream>
#include "TeleportTrap.h"
#include "Player.h"
#include "Floor.h"

void dc::model::TeleportTrap::onSpring(dc::model::Player &player) {
    std::cout << "You feel a strange nauseating feeling in the lower part of your bowels. Your life flashes besides "
              << "your eyes, when you suddenly hear a voice inside your head, 'MUST YOU DIE NOW, I'M IN THE MIDDLE OF "
              << "SOMETHING, YOU SEE'.\n";
    std::cout << "Poof!\n";
    std::cout << "You suddenly find yourself in a different room, though it's almost like you've been here before.\n";

    dc::model::Room *room = player.room();
    dc::model::Floor &floor = *room->floor();

    player.setRoom(&floor.startRoom());

    std::cout << "You have been teleported to the start room." << std::endl;
}

const std::string dc::model::TeleportTrap::name() {
    return "peculiar glyph";
}
