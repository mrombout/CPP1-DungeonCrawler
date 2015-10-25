#include "UseCommand.h"
#include "Item.h"
#include "Player.h"

UseCommand::UseCommand(dc::model::Player &player) :
    mPlayer(player) {

}

void UseCommand::execute() const {
    /*
    // look up item in inventory
    dc::model::Item *item = mPlayer.inventory().findItem(mItemName);
    if(item != nullptr) {
        item->use();
    }

    // TODO: Use items in room? e.g. staircase?
    */
}
