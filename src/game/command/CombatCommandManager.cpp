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
#include "LightRoomCommand.h"
#include "CastCommand.h"
#include "ClearCommand.h"

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
            } else if(commandName == "light") {
                command = LightRoomCommand::create(parameters);
            } else if (commandName == "clear") {
                command = ClearCommand::create(parameters);
            } else if(commandName == "") {
                command = NullCommand::create(parameters);
            } else {
                std::cout << "Unknown command, please use one of the following commands:\n";
                std::cout << "- attack [enemy number] - To attack the desired enemy\n";
                std::cout << "- flee - To flee the scene\n";
                std::cout << "- inv - To display the items in your inventory\n";
                std::cout << "- use [item name] - To use the specified item\n";
                std::cout << "- equip [item name] - To equip the specified weapon\n";
                std::cout << "- stats - To display your current statistics\n";
                std::cout << "- cast [magic] - To cast a magic spell\n";
                std::cout << "- light - To enlight nearby torches\n";
                std::cout << "- clear - To clear the console" << std::endl;
            }

            if(!command)
                command = dc::game::NullCommand::create(parameters);

            return command;
        }
    }
}
