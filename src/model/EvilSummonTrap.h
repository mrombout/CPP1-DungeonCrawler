#ifndef DUNGEONCRAWLER_EVILSUMMONTRAP_H
#define DUNGEONCRAWLER_EVILSUMMONTRAP_H

#include "Trap.h"

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace model {
        class EvilSummonTrap : public Trap {
            void spring(dc::model::Player &player) override;
        };
    }
}


#endif //DUNGEONCRAWLER_EVILSUMMONTRAP_H
