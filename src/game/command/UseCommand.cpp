#include "UseCommand.h"
#include "Game.h"
#include "item/Item.h"
#include "Player.h"
#include "util/ServiceLocator.h"

namespace dc {
    namespace game {
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

        UseCommand *UseCommand::create(Parameters parameters) {
            return new UseCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player());
        }
    }
}
