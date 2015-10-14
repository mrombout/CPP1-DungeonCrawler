#ifndef DUNGEONCRAWLER_BEARTRAP_H
#define DUNGEONCRAWLER_BEARTRAP_H

#include "Trap.h"

namespace dc {
    namespace model {
        class BearTrap : public Trap {
            void spring(dc::model::Player &player) override;
        };
    }
}

#endif //DUNGEONCRAWLER_BEARTRAP_H
