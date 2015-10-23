#include <sstream>
#include <vector>
#include "CommandManager.h"
#include "command.h"
#include "LookCommand.h"
#include "InventoryCommand.h"
#include "MapCommand.h"
#include "GoToCommand.h"

namespace dc {
    namespace game {
        engine::Command *CommandManager::create(std::string name) const {

            // Split input by spaces
            std::stringstream input(name);
            std::string s;
            std::vector<std::string> parameters;

            while (getline(input, s, ' ')) {
                parameters.push_back(s.c_str());
            }

            std::string commandName;
            commandName =  (parameters.size() > 0) ? parameters[0] : name;

            if (parameters.size() > 0) {
                // Remove first element from vector (the command name)
                parameters.erase(parameters.begin());
            }

            if(commandName == "look") {
                return new LookCommand();
            } else if(commandName == "map") {
				return new MapCommand();
            } else if (commandName == "use") {
                return new InventoryCommand();
            } else if (commandName == "goto") {
                return new GoToCommand(parameters);
            }

            return nullptr;
        }
    }
}
