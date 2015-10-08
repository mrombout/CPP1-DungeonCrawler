#include <iostream>
#include "LookCommand.h"

namespace dc {
    void game::LookCommand::execute(engine::CommandParameters &parameters) const {
        std::cout << "Dankstorm!" << std::endl;
    }
}