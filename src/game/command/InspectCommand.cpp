#include <iostream>
#include "InspectCommand.h"
#include "Trap.h"

void InspectCommand::execute(dc::engine::CommandParameters &parameters) const {
    std::cout << "You take a stern look across the room.\n";

    // TODO: Hoe hogere perception, hoe meer kan dat speler traps ziet.

    const std::vector<dc::model::Trap*> &traps = parameters.player().room().traps();
    if(!traps.empty()) {
        for(dc::model::Trap *trap : traps) {
            std::cout << "You notice a " << trap->name() << ".\n";
            trap->discover();
        }
    }
}
