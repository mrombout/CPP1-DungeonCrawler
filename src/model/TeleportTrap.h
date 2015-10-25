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

        public:
            virtual const std::string name();

            virtual void onSpring(dc::model::Player &player) override;
        };
    }
}

#endif //DUNGEONCRAWLER_TELEPORTTRAP_H
