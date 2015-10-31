#ifndef DUNGEONCRAWLER_BEARTRAP_H
#define DUNGEONCRAWLER_BEARTRAP_H

#include "Trap.h"

namespace dc {
    namespace model {
        class BearTrap : public Trap {
        public:
            static const std::string ID;

            virtual const std::string id() const;
            virtual const std::string name();

            void onSpring(dc::model::Player &player) override;
        };
    }
}

#endif //DUNGEONCRAWLER_BEARTRAP_H
