#include <iostream>
#include "util/console.h"
#include "Render.h"

namespace dc {
    namespace game {
        void Render::mobList(const std::vector<dc::model::Mob *> &mobs) {
            for(auto it = mobs.cbegin(); it != mobs.cend(); ++it) {
                int index = std::distance(mobs.cbegin(), it);
                dc::model::Mob* mob = (*it);

                // loop through colors 2 to 8
                std::cout << csl::color(index % 7 + 2) << "[" << index + 1 << "] a " << mob->name() << "(" << mob->health() << "/" << mob->maxHealth() << ")" << "\n";
            }
        }
    }
}
