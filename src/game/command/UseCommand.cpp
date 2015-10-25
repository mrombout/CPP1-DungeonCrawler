#include "UseCommand.h"

UseCommand::UseCommand(std::string item) :
    mItemName(item) {

}

void UseCommand::execute(dc::engine::CommandParameters &parameters) const {
    dc::model::Player &player = parameters.player();

    // look up item in inventory
    dc::model::Item *item = player.inventory().findItem(mItemName);
    if(item != nullptr) {
        item->use();
    }

    // TODO: Use items in room? e.g. staircase?
}
