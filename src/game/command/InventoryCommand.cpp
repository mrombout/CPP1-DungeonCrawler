#include <iostream>
#include <util/console.h>
#include "InventoryCommand.h"
#include "Game.h"
#include "Player.h"
#include "util/ServiceLocator.h"
#include "item/Item.h"

namespace dc {
    game::InventoryCommand::InventoryCommand(model::Player &player) :
        mPlayer(player) {

    }

    void game::InventoryCommand::execute() const {
        std::cout << "You look into your backpack and see: \n\n";

        std::vector<dc::model::Item*> items = mPlayer.inventory().items();
        if (items.empty()) {
            std::cout << "Nothing! It's empty! Is there a hole in it or something?!";
        } else {
            for (std::vector<int>::size_type i = 0; i != items.size(); ++i) {
                std::cout << csl::color(csl::WHITE) << " - " << items[i]->name() << "\n";
                std::cout << csl::color(csl::GREY) << "\t" << items[i]->description() << "\n";

            }
        }
    }

    game::InventoryCommand *game::InventoryCommand::create(Parameters parameters) {
        return new dc::game::InventoryCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player());
    }

    bool game::InventoryCommand::isAction() const {
        return false;
    }
}