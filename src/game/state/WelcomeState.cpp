#include <iostream>
#include <fstream>
#include <string>
#include "command/ExitCommand.h"
#include "command/NewGameCommand.h"
#include "command/ChangeStateCommand.h"
#include "command/LoadGameCommand.h"
#include "WelcomeState.h"
#include "OptionsState.h"
#include "util/ServiceLocator.h"
#include "util/console.h"
#include "command/Parameters.h"

namespace dc {
    namespace game {
        WelcomeState::WelcomeState() {

        }

        WelcomeState::~WelcomeState() {

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
            std::cout << csl::color(csl::GREEN) << "\t(N)ew Game\n\t(L)oad Game\n\t(O)ptions\n\t(E)xit" << std::endl;

            std::string input;
            std::cin >> input;
            std::cin.ignore(1000, '\n');

            return input;
        }

        dc::game::Command *WelcomeState::onEval(std::string input) {
            dc::game::Parameters parameters(input);

            if (input == "n") {
                return ServiceLocator::getInstance().create<NewGameCommand>();
            } else if(input == "l") {
                return dc::game::LoadGameCommand::create();
            } else if(input == "o") {
                return dc::game::ChangeStateCommand::create(new dc::game::OptionsState());
			} else if (input == "e"){
				return dc::game::ExitCommand::create(parameters);
			}

            return nullptr;
        }

        void WelcomeState::onPrint(game::GameLoop &game, game::Command *command) {
            command->execute();
        }
    }
}