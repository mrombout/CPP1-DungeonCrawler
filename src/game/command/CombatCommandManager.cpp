#include <iostream>
#include "state/CombatState.h"
#include "AttackCommand.h"
#include "FleeCommand.h"
#include "InventoryCommand.h"
#include "NullCommand.h"
#include "UseCommand.h"
#include "util/ServiceLocator.h"

CombatCommandManager::CombatCommandManager(CombatState &combatState) :
    mCombatState(combatState) {

}

dc::engine::Command *CombatCommandManager::create(std::string input) const {
    Parameters parameters(input);

    dc::engine::Command *command = nullptr;
    const std::string commandName = parameters.commandName();
    if(commandName == "attack") {
        command = AttackCommand::create(parameters);
    } else if(commandName == "flee") {
        command = FleeCommand::create(parameters);
    } else if(commandName == "inv") {
        command = dc::game::InventoryCommand::create(parameters);
    } else if(commandName == "use") {
        command = UseCommand::create(parameters);
    }

    if(!command)
        command = dc::game::NullCommand::create(parameters);

    return command;
}

dc::engine::Command *CombatCommandManager::createAttackCommand(std::vector<std::string> &inputs) const {
    /*
    if(inputs.size() != 2) {
        std::cout << "Not enough arguments" << std::endl;
        return new dc::game::NullCommand();
    }

    int mobNum = Number::toLong(inputs[1]);
    if(mobNum == -1) {
        std::cout << "Which monsters is that?!" << std::endl;
        return new dc::game::NullCommand();
    }

    dc::model::Mob *mob = mCombatState.mob(mobNum);
    if(mob == nullptr) {
        std::cout << "Which monster is that?" << std::endl;
        return new dc::game::NullCommand();
    }

    return new AttackCommand(*mob);
    */
}
