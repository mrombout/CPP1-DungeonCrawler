#include <iostream>
#include "MobCallTrap.h"
#include "Player.h"
#include "Passage.h"

void dc::model::MobCallTrap::onSpring(dc::model::Player &player) {
    std::cout << "You trip over a small piece of string triggering a lock to disengage and drop a massive boulder on "
              << "the floor. You manage to escape, but you might not be the only one that heard that massive bang."
              << std::endl;

    dc::model::Room &room = player.room();
    std::vector<dc::model::Mob*> mobs;

    // retrieve all mobs from neighbouring rooms
    for(dc::model::Passage *passage : room.adjacantPassages()) {
        if(passage == nullptr)
            continue;

        dc::model::Room &otherRoom = passage->otherSide(&room);
        const std::vector<dc::model::Mob*> otherMobs = otherRoom.mobs();
        for(dc::model::Mob* otherMob : otherMobs) {
            mobs.push_back(otherMob);
            otherRoom.removeMob(otherMob);
        }
    }

    // add all mobs to current room
    if(!mobs.empty()) {
        std::cout << "You hear steps coming your way..." << std::endl;
        for(dc::model::Mob* mob : mobs) {
            room.addMob(mob);
        }
    }
}

const std::string dc::model::MobCallTrap::name() {
    return "evil summon trap";
}
