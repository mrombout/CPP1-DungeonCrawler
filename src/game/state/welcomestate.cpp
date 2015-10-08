#include <iostream>
#include <fstream>
#include <string>
#include <command/NewGameCommand.h>
#include "welcomestate.h"

namespace dc {
namespace game {

    WelcomeState::WelcomeState()
    {

    }

    void WelcomeState::onInitialize(engine::GameLoop *game)
    {
        std::ifstream file("assets/intro.txt");
        std::string line;
        
        while(getline(file, line)) {
            std::cout << line << std::endl;
        }
    }

    void WelcomeState::onEnter(engine::GameLoop *game)
    {
        std::cout << mWelcomeMsg << std::endl;
    }

    std::string WelcomeState::onRead()
    {
        std::cout << "\t(N)ew GameLoop \n\t(L)oad GameLoop \n\t(E)xit" << std::endl;

        std::string input;
        std::cin >> input;

        return input;
    }

    engine::Command *WelcomeState::onEval(std::string input)
    {
        if(input == "n") {
            return new NewGameCommand();
        }
    }

    void WelcomeState::onPrint(engine::GameLoop &game, engine::Command *command) {
        command->execute(game);
    }

}
}