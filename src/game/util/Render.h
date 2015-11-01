#ifndef DUNGEONCRAWLER_RENDER_H
#define DUNGEONCRAWLER_RENDER_H

#include <vector>
#include <GameLoop.h>
#include "Mob.h"
#include "Player.h"

namespace dc {
    namespace game {
        class Render {
        public:
            static void mobList(const std::vector<dc::model::Mob*> &mobs);
            static bool prompt(model::Player &player, dc::game::GameLoop &gameLoop);
        };
    }
}

#endif //DUNGEONCRAWLER_RENDER_H
