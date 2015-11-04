#include <Options.h>
#include "util/console.h"
#include "util/ServiceLocator.h"
#include "OptionsState.h"
#include "command/NullCommand.h"
#include "command/ChangeOptionCommand.h"
#include "command/PopStateCommand.h"

namespace dc {
    namespace game {
        OptionsState::OptionsState() {

        }

        OptionsState::~OptionsState() {

        }

        void OptionsState::onInitialize(dc::game::GameLoop *game) {

        }

        void OptionsState::onEnter(dc::game::GameLoop *game) {

        }

        std::string OptionsState::onRead() {
            std::cout << "Options\n\n";

            dc::model::Options &options = ServiceLocator::getInstance().resolve<dc::model::Options>();
            std::map<std::string, std::string> allOptions = options.all();
            for(auto it = allOptions.cbegin(); it != allOptions.cend(); ++it) {
                std::cout << " - " << it->first << ": " << it->second << "\n";
            }

            std::cout << csl::color(csl::GREEN) << "\nUse \"change <key> <value>\" to change a value\n\n";

            std::cout << "Command: ";

            std::string input;

            std::getline(std::cin, input);

            return input;
        }

        dc::game::Command *OptionsState::onEval(std::string input) {
            Parameters parameters(input);

            if(parameters.commandName() == "back") {
                return PopStateCommand::create();
            } else if(parameters.commandName() != "change" || parameters.num() != 2) {
                std::cout << csl::color(csl::RED) << "Unrecognized command.\n";
                return new dc::game::NullCommand();
            }

            return new ChangeOptionCommand(parameters.param(0), parameters.param(1));
        }

        void OptionsState::onPrint(dc::game::GameLoop &game, dc::game::Command *command) {
            command->execute();
        }
    }
}
