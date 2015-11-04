#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <string>
#include "command.h"
#include "statemanager.h"

namespace dc {
    namespace game {
        class GameLoop : public StateManager {
        public:
            explicit GameLoop();

            ~GameLoop();

            void start();

            void stop();

            void quit();

        private:
            bool mLoop;
        };

    }
}

#endif // GAMELOOP_H
