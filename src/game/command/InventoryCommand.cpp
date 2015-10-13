//
// Created by Robin de Mug on 10/12/15.
//

#include <iostream>
#include "InventoryCommand.h"

namespace dc {
    void game::InventoryCommand::execute(engine::CommandParameters &parameters) const {
        std::cout << parameters.player().inventory().description() << std::endl;
    }
}