#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <string>
#include "command.h"
#include "statemanager.h"

namespace dc {
    namespace engine {

        class Game : public StateManager {
        public:
            explicit Game();

            ~Game();

            void start();

            void stop();

            void quit();

        private:
            bool mLoop;
        };

    }
}

#endif // GAMELOOP_H
