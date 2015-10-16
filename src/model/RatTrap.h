#ifndef DUNGEONCRAWLER_RATTRAP_H
#define DUNGEONCRAWLER_RATTRAP_H

#include "Trap.h"

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace model {
        class RatTrap  : public Trap {
            void spring(dc::model::Player &player) override;
        };
    }
}

#endif //DUNGEONCRAWLER_RATTRAP_H
