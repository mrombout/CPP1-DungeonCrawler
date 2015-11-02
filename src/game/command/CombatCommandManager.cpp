#include <iostream>
#include "state/CombatState.h"
#include "AttackCommand.h"
#include "FleeCommand.h"
#include "InventoryCommand.h"
#include "NullCommand.h"
#include "UseCommand.h"
#include "util/ServiceLocator.h"
#include "EquipCommand.h"
#include "StatsCommand.h"
#include "CastCommand.h"

namespace dc {
    namespace game {
        CombatCommandManager::CombatCommandManager(CombatState &combatState) :
                mCombatState(combatState) {

        }

        dc::game::Command *CombatCommandManager::create(std::string input) const {
            Parameters parameters(input);

            dc::game::Command *command = nullptr;
            const std::string commandName = parameters.commandName();
            if(commandName == "attack") {
                command = AttackCommand::create(parameters);
            } else if(commandName == "flee") {
                command = FleeCommand::create(parameters);
            } else if(commandName == "inv") {
                command = dc::game::InventoryCommand::create(parameters);
            } else if(commandName == "use") {
                command = UseCommand::create(parameters);
            } else if(commandName == "equip") {
                command = EquipCommand::create(parameters);
            } else if(commandName == "stats") {
                command = StatsCommand::create(parameters);
            } else if(commandName == "cast") {
                command = CastCommand::create(parameters);
            }

            if(!command)
                command = dc::game::NullCommand::create(parameters);

            return command;
        }
    }
}
