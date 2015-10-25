#ifndef DUNGEONCRAWLER_TRAP_H
#define DUNGEONCRAWLER_TRAP_H

#include <string>

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace model {
        class Trap {
        public:
            Trap();
            virtual ~Trap() { }

            bool isDiscovered();
            void discover();

            bool isSprung();
            void spring(dc::model::Player &player);

            virtual const std::string name() = 0;
            virtual void onSpring(dc::model::Player &player) = 0;

        private:
            bool mDiscovered;
            bool mSprung;
        };
    }
}

#endif //DUNGEONCRAWLER_TRAP_H
