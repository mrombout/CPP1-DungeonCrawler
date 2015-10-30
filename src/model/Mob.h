#ifndef DUNGEONCRAWLER_MOB_H
#define DUNGEONCRAWLER_MOB_H

#include "Character.h"

namespace dc {
    namespace model {
        class Mob : public Character {
        public:
            void kill();
            virtual void damage(unsigned int pDamage) override;
        };
    }
}

#endif //DUNGEONCRAWLER_MOB_H
