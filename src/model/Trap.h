#ifndef DUNGEONCRAWLER_TRAP_H
#define DUNGEONCRAWLER_TRAP_H

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace model {
        class Trap {
        public:
            virtual ~Trap() { }

            virtual void spring(dc::model::Player &player) = 0;
        };
    }
}


#endif //DUNGEONCRAWLER_TRAP_H
