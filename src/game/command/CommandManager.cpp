#include "CommandManager.h"
#include "command.h"
#include "LookCommand.h"
#include "InventoryCommand.h"
#include "MapCommand.h"

namespace dc {
    namespace game {
        engine::Command *CommandManager::create(std::string name) const {
            if(name == "look") {
                return new LookCommand();
            } else if(name == "map") {
				return new MapCommand();
            } else if (name == "use") {
                return new InventoryCommand();
            }

            return nullptr;
        }
    }
}
