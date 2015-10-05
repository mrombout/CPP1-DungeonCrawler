#include <iostream>
#include <fstream>
#include <string>
#include "welcomestate.h"

namespace dc {
namespace game {

    WelcomeState::WelcomeState()
    {

    }

    void WelcomeState::onInitialize(engine::Game *game)
    {
        std::ifstream file("assets/intro.txt");
        std::string line;
        
        while(getline(file, line)) {
            std::cout << line << std::endl;
        }
    }

    void WelcomeState::onEnter(engine::Game *game)
    {
        std::cout << mWelcomeMsg << std::endl;
    }

    std::string WelcomeState::onRead()
    {
        std::cout << "\t(N)ew Game \n\t(L)oad Game \n\t(E)xit" << std::endl;

        std::string input;
        std::cin >> input;

        return input;
    }

    engine::Command *WelcomeState::onEval(std::string input)
    {
        return 0;
    }

}
}
