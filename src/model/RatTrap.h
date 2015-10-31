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
        public:
            static const std::string ID;

            virtual const std::string id() const;
            virtual const std::string name();

            void onSpring(dc::model::Player &player) override;
        };
    }
}

#endif //DUNGEONCRAWLER_RATTRAP_H
