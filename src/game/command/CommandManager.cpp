#include "CommandManager.h"
#include "command.h"
#include "LookCommand.h"

namespace dc {
    namespace game {
        engine::Command *CommandManager::create(std::string name) const {
            if(name == "look") {
                return new LookCommand();
            }

            return nullptr;
        }
    }
}
