#include <iostream>
#include "GameLoop.h"

namespace dc {
namespace engine {

    GameLoop::GameLoop() : StateManager(this) {
        
    }

    GameLoop::~GameLoop() {

    }

    void GameLoop::start() {
		std::cout << "START - GameLoop" << std::endl;

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
        std::cout << "STOP - GameLoop";

        mLoop = false;
        quit();
    }

    void GameLoop::quit() {
        
    }

}
}
