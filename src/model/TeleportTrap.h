#ifndef DUNGEONCRAWLER_TELEPORTTRAP_H
#define DUNGEONCRAWLER_TELEPORTTRAP_H

#include "Trap.h"

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace model {
        class TeleportTrap : public Trap {
            void spring(dc::model::Player &player) override;
        };
    }
}


#endif //DUNGEONCRAWLER_TELEPORTTRAP_H
