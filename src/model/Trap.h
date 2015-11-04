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
            bool spring(dc::model::Player &player);

            bool isDismantled();
            void dismantle();

            virtual const std::string id() const = 0;
            virtual const std::string name() = 0;
            virtual void onSpring(dc::model::Player &player) = 0;

            friend std::ostream &operator<<(std::ostream &output, const Trap &t);
            friend std::istream &operator>>(std::istream &input, Trap &t);

        private:
            bool mDiscovered;
            bool mSprung;
            bool mDismantled;
        };
    }
}

#endif //DUNGEONCRAWLER_TRAP_H
