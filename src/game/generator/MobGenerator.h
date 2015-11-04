#ifndef DUNGEONCRAWLER_MOBGENERATOR_H
#define DUNGEONCRAWLER_MOBGENERATOR_H

#include "Mob.h"
#include <unordered_map>

namespace dc {
    namespace game {
        class MobGenerator {
        public:
            static dc::model::Mob *generate(unsigned int level);
            static dc::model::Mob *create(int id, unsigned int level);

            static model::Mob *createMob(std::unordered_map<std::string, std::string> &mobProps, unsigned int level);
        };
    }
}

#endif //DUNGEONCRAWLER_MOBGENERATOR_H
