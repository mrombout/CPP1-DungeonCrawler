#include <iostream>
#include "InspectCommand.h"
#include "Trap.h"
#include "Player.h"
#include "util/ServiceLocator.h"

InspectCommand::InspectCommand(dc::model::Game &game) :
    mGame(game) {

}

void InspectCommand::execute() const {
    std::cout << "You take a stern look across the room.\n";

    // TODO: Hoe hogere perception, hoe meer kan dat speler traps ziet.

    const std::vector<dc::model::Trap*> &traps = mGame.player().room().traps();
    if(!traps.empty()) {
        for(dc::model::Trap *trap : traps) {
            std::cout << "You notice a " << trap->name() << ".\n";
            trap->discover();
        }
    }
}

InspectCommand *InspectCommand::create(Parameters parameters) {
    return new InspectCommand(ServiceLocator::getInstance().resolve<dc::model::Game>());
}
