#include <iostream>
#include <fstream>
#include <string>
#include "command/NewGameCommand.h"
#include "WelcomeState.h"
#include "util/ServiceLocator.h"
#include "util/console.h"

namespace dc {
    namespace game {
        WelcomeState::WelcomeState() {

        }

        void WelcomeState::onInitialize(engine::GameLoop *game) {
            std::ifstream file("assets/intro.txt");
            std::string line;

            std::cout << csl::color(csl::GREY);
            while (getline(file, line)) {
                std::cout << line << std::endl;
            }
        }

        void WelcomeState::onEnter(engine::GameLoop *game) {
            std::cout << mWelcomeMsg << std::endl;
        }

        std::string WelcomeState::onRead() {
            std::cout << csl::color(csl::GREEN) << "\t(N)ew GameLoop \n\t(L)oad GameLoop \n\t(E)xit" << std::endl;

            std::string input;
            std::cin >> input;
            std::cin.ignore(1000, '\n');

            return input;
        }

        engine::Command *WelcomeState::onEval(std::string input) {
            if (input == "n") {
                return ServiceLocator::getInstance().create<NewGameCommand>();
            }

            return nullptr;
        }

        void WelcomeState::onPrint(engine::GameLoop &game, engine::Command *command) {
            command->execute();
        }
    }
}