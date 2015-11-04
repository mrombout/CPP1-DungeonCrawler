#include <iostream>
#include "MobCallTrap.h"
#include "Player.h"
#include "Passage.h"

namespace dc {
    namespace model {
        const std::string MobCallTrap::ID = "MOBCALLTRAP";

        void MobCallTrap::onSpring(Player &player) {
            std::cout << "You trip over a small piece of string triggering a lock to disengage and drop a massive boulder on "
            << "the floor. You manage to escape, but you might not be the only one that heard that massive bang."
            << std::endl;

            Room *room = player.room();
            std::vector<Mob*> mobs;

            // retrieve all mobs from neighbouring rooms
            for(Passage *passage : room->adjacantPassages()) {
                if(passage == nullptr)
                    continue;

                Room &otherRoom = passage->otherSide(*room);
                const std::vector<Mob*> otherMobs = otherRoom.mobs();
                for(Mob* otherMob : otherMobs) {
                    mobs.push_back(otherMob);
                    otherRoom.removeMob(otherMob);
                }
            }

            // add all mobs to current room
            if(!mobs.empty()) {
                std::cout << "You hear steps coming your way..." << std::endl;
                for(Mob* mob : mobs) {
                    room->addMob(mob);
                }
            }
        }

        const std::string MobCallTrap::name() {
            return "evil summon trap";
        }

        const std::string MobCallTrap::id() const {
            return ID;
        }
    }
}
