#include <sstream>
#include <vector>
#include "CommandManager.h"
#include "command.h"
#include "LookCommand.h"
#include "InventoryCommand.h"
#include "MapCommand.h"
#include "GoToCommand.h"
#include "UseCommand.h"
#include "StatsCommand.h"
#include "InspectCommand.h"
#include "NullCommand.h"
#include "AttackCommand.h"
#include "util/ServiceLocator.h"

namespace dc {
    namespace game {
        engine::Command *CommandManager::create(std::string input) const {
            Parameters parameters(input);

            dc::engine::Command *command = nullptr;
            const std::string &commandName = parameters.commandName();
            if(commandName == "look") {
                command = dc::game::LookCommand::create();
            } else if(commandName == "map") {
                command = dc::game::MapCommand::create(parameters);
            } else if (commandName == "inv") {
                command = dc::game::InventoryCommand::create(parameters);
            } else if (commandName == "goto") {
                command = dc::game::GoToCommand::create(parameters);
            } else if(commandName == "use") {
                command = UseCommand::create(parameters);
            } else if(commandName == "stats") {
                command = StatsCommand::create(parameters);
            } else if(commandName == "inspect") {
                command = InspectCommand::create(parameters);
            } else if (commandName == "attack") {
                command = AttackCommand::create(parameters);
            }

            if(!command)
                command = new NullCommand();

            return command;
        }
    }
}
