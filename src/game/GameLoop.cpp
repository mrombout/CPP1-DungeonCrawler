#include <iostream>
#include "GameLoop.h"
#include "util/console.h"

namespace dc {
    namespace game {
        GameLoop::GameLoop() : StateManager(this) {

        }

        GameLoop::~GameLoop() {

        }

        void GameLoop::start() {
            csl::log() << "START - GameLoop" << std::endl;

            if(currentState())
                mLoop = true;

            do {
                Command *command;
                do {
                    std::string input = read();
                    command = eval(input);
                } while(!command);

                onPrint(*this, command);
                delete command;
            } while(mLoop);
        }

        void GameLoop::stop() {
            csl::log() << "STOP - GameLoop";

            mLoop = false;
            quit();
        }

        void GameLoop::quit() {

        }
    }
}
