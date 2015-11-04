#ifndef DUNGEONCRAWLER_NEARDEATHTRAP_H
#define DUNGEONCRAWLER_NEARDEATHTRAP_H

#include "Trap.h"

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace model {
        class NearDeathTrap : public Trap {
        public:
            NearDeathTrap(int health);

            static const std::string ID;

            virtual const std::string id() const;
            virtual const std::string name();
            virtual void onSpring(dc::model::Player &player) override;

        private:
            int mHealth;
        };
    }
}

#endif //DUNGEONCRAWLER_NEARDEATHTRAP_H
