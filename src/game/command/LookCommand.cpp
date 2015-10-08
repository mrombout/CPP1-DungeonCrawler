#include <iostream>
#include "LookCommand.h"

namespace dc {
    void game::LookCommand::execute(engine::CommandParameters &parameters) const {
        std::cout << parameters.player().room().description() << std::endl;
    }
}