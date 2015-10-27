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
#include "ClearCommand.h"

namespace dc {
    game::Command *CommandManager::create(std::string input) const {
        dc::game::Parameters parameters(input);

        dc::game::Command *command = nullptr;
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
            command = dc::game::UseCommand::create(parameters);
        } else if(commandName == "stats") {
            command = dc::game::StatsCommand::create(parameters);
        } else if(commandName == "inspect") {
            command = dc::game::InspectCommand::create(parameters);
        } else if (commandName == "attack") {
            command = dc::game::AttackCommand::create(parameters);
        } else if (commandName == "clear") {
            command = dc::game::ClearCommand::create(parameters);
        }

        if(!command)
            command = new dc::game::NullCommand();

        return command;
    }
}
