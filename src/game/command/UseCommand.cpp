#include <iostream>
#include "UseCommand.h"
#include "Game.h"
#include "item/Item.h"
#include "Player.h"
#include "util/ServiceLocator.h"

namespace dc {
    namespace game {
        UseCommand::UseCommand(model::Player &player, const std::string itemName) :
                mPlayer(player),
                mItemName(itemName) {

        }

        void UseCommand::execute() const {
            // look up item in inventory
            dc::model::Item *item = mPlayer.inventory().findItem(mItemName);
            if(item != nullptr) {
                item->use(mPlayer);
            }

            // TODO: Use items in room? e.g. staircase?
        }

        UseCommand *UseCommand::create(Parameters parameters) {
            if(parameters.num() != 1) {
                std::cout << "What should I use?" << std::endl;
                return nullptr;
            }

            return new UseCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player(),
                                  parameters.param(0));
        }
    }
}
