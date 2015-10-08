#include <iostream>
#include "game.h"

namespace dc {
namespace engine {

    Game::Game() : StateManager(this) {
        
    }

    Game::~Game() {

    }

    void Game::start() {
		std::cout << "START - Game" << std::endl;

        if(currentState())
            mLoop = true;

        do {
            Command *command;
            do {
                std::string input = read();
                command = eval(input);
            } while(!command);

            onPrint(*this, command);
        } while(mLoop);
    }

    void Game::stop() {
        std::cout << "STOP - Game";

        mLoop = false;
        quit();
    }

    void Game::quit() {
        
    }

}
}
