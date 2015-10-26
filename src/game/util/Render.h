#ifndef DUNGEONCRAWLER_RENDER_H
#define DUNGEONCRAWLER_RENDER_H

#include <vector>
#include "Mob.h"

namespace dc {
    namespace game {
        class Render {
        public:
            static void mobList(const std::vector<dc::model::Mob*> &mobs);
        };
    }
}

#endif //DUNGEONCRAWLER_RENDER_H
