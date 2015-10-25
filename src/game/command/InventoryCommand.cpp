#include <iostream>
#include "InventoryCommand.h"
#include "Game.h"
#include "Player.h"
#include "util/ServiceLocator.h"

namespace dc {
    game::InventoryCommand::InventoryCommand(model::Player &player) :
        mPlayer(player) {

    }

    void game::InventoryCommand::execute() const {
        std::cout << mPlayer.inventory().description() << std::endl;
    }

    game::InventoryCommand *game::InventoryCommand::create(Parameters parameters) {
        return new dc::game::InventoryCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player());
    }
}