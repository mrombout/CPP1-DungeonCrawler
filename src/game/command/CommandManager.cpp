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
#include "RestCommand.h"
#include "EquipCommand.h"
#include "SaveCommand.h"
#include "CheatMob.h"
#include "LightRoomCommand.h"
#include "CastCommand.h"

namespace dc {
    game::Command *CommandManager::create(std::string input) const {
        dc::game::Parameters parameters(input);

        dc::game::Command *command = nullptr;
        const std::string &commandName = parameters.commandName();
        if(commandName == "attack") {
            command = dc::game::AttackCommand::create(parameters);
        } else if(commandName == "look") {
            command = dc::game::LookCommand::create(parameters);
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
        } else if (commandName == "clear") {
            command = dc::game::ClearCommand::create(parameters);
        } else if (commandName == "rest") {
            command = dc::game::RestCommand::create(parameters);
        } else if(commandName == "equip") {
            command = dc::game::EquipCommand::create(parameters);
        } else if(commandName == "save") {
            command = dc::game::SaveCommand::create(parameters);
        } else if(commandName == "cheatmob") {
            command = dc::game::CheatMob::create(parameters);
        } else if(commandName == "light") {
            command = dc::game::LightRoomCommand::create(parameters);
        } else if(commandName == "cast") {
            command = dc::game::CastCommand::create(parameters);
        } else if(commandName == "") {
            command = dc::game::NullCommand::create(parameters);
        } else if(commandName == "exit") {
            exit(0);
        } else {
            std::cout << "Unknown command, please use one of the following commands:\n";
            std::cout << "- attack [enemy number] - To attack the desired enemy\n";
            std::cout << "- map - To display a map of the dungeon\n";
            std::cout << "- inv - To display the items in your inventory\n";
            std::cout << "- use [item name] - To use the specified item\n";
            std::cout << "- stats - To display your current statistics\n";
            std::cout << "- inspect - To inspect the current room\n";
            std::cout << "- rest - To restore your health\n";
            std::cout << "- equip [item name] - To equip the specified weapon\n";
            std::cout << "- light - To enlight nearby torches\n";
            std::cout << "- cast [spell name] - To cast a spell\n";
            std::cout << "- clear - To clear the console\n";
            std::cout << "- save - To save the game\n";
            std::cout << "- exit - To exit the game (WITHOUT saving)" << std::endl;
        }

        if(!command) {
            command = new dc::game::NullCommand();
            std::cout << "Command is not recognized." << std::endl;
        }

        return command;
    }
}
