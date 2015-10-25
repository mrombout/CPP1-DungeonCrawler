#include <sstream>
#include <vector>
#include <util/ServiceLocator.h>
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
#include "Parameters.h"

namespace dc {
    namespace game {
        engine::Command *CommandManager::create(std::string input) const {
            Parameters parameters(input);

            dc::engine::Command *command = nullptr;
            const std::string &commandName = parameters.commandName();
            if(commandName == "look") {
                command = ServiceLocator::getInstance().create<dc::game::LookCommand>();
            } else if(commandName == "map") {
                command = ServiceLocator::getInstance().create<dc::game::MapCommand>();
            } else if (commandName == "inv") {
                command = ServiceLocator::getInstance().create<dc::game::InventoryCommand>();
            } else if (commandName == "goto") {
                command = ServiceLocator::getInstance().create<dc::game::GoToCommand>();
            } else if(commandName == "use") {
                command = ServiceLocator::getInstance().create<UseCommand>();
            } else if(commandName == "stats") {
                command = ServiceLocator::getInstance().create<StatsCommand>();
            } else if(commandName == "inspect") {
                command = ServiceLocator::getInstance().create<InspectCommand>();
            } else {
                command = new NullCommand();
            }

            return nullptr;
        }
    }
}
