#include <iostream>
#include <fstream>
#include <string>
#include "command/NewGameCommand.h"
#include "command/ChangeStateCommand.h"
#include "command/LoadGameCommand.h"
#include "WelcomeState.h"
#include "OptionsState.h"
#include "util/ServiceLocator.h"
#include "util/console.h"

namespace dc {
    namespace game {
        WelcomeState::WelcomeState() {

        }

        void WelcomeState::onInitialize(game::GameLoop *game) {
            std::ifstream file("assets/intro.txt");
            std::string line;

            std::cout << csl::color(csl::GREY);
            while (getline(file, line)) {
                std::cout << line << std::endl;
            }
        }

        void WelcomeState::onEnter(game::GameLoop *game) {
            std::cout << mWelcomeMsg << std::endl;
        }

        std::string WelcomeState::onRead() {
            std::cout << csl::color(csl::GREEN) << "\t(N)ew GameLoop\n\t(L)oad GameLoop\n\t(O)ptions\n\t(E)xit" << std::endl;

            std::string input;
            std::cin >> input;
            std::cin.ignore(1000, '\n');

            return input;
        }

        dc::game::Command *WelcomeState::onEval(std::string input) {
            if (input == "n") {
                // TODO: Replace with ChangeStateCommand
                return ServiceLocator::getInstance().create<NewGameCommand>();
            } else if(input == "l") {
                return dc::game::LoadGameCommand::create();
            } else if(input == "o") {
                // TODO: Delete that state somewhere
                return dc::game::ChangeStateCommand::create(new dc::game::OptionsState());
            }

            return nullptr;
        }

        void WelcomeState::onPrint(game::GameLoop &game, game::Command *command) {
            command->execute();
        }
    }
}