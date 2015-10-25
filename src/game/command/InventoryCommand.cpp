//
// Created by Robin de Mug on 10/12/15.
//

#include <iostream>
#include "Player.h"
#include "InventoryCommand.h"

namespace dc {
    game::InventoryCommand::InventoryCommand(model::Player &player) :
        mPlayer(player) {

    }

    void game::InventoryCommand::execute() const {
        std::cout << mPlayer.inventory().description() << std::endl;
    }
}