#include "util/Random.h"
#include "Mob.h"
#include "Flipendo.h"
#include "Room.h"

namespace dc {
    namespace model {
        void Flipendo::cast(dc::model::Character &character, dc::model::Game &game) const {
            dc::model::Room *room = character.room();
            for(dc::model::Mob* mob : room->mobs()) {
                int damage = Random::nextInt(1, 10);
                std::cout << "A bolt of light hits the " << mob->name() << ", hitting " << damage << " hp." << std::endl;
                mob->damage(damage);
            }
        }
    }
}
