#include <iostream>
#include "InspectCommand.h"
#include "Game.h"
#include "Trap.h"
#include "Player.h"
#include "util/ServiceLocator.h"

namespace dc {
    namespace game {
        InspectCommand::InspectCommand(dc::model::Game &game, dc::game::ItemLoader &itemLoader) :
                mGame(game),
                mItemLoader(itemLoader) {

        }

        void InspectCommand::execute() const {
            std::cout << "You take a stern look across the room.\n";

            // TODO: Hoe hogere perception, hoe meer kan dat speler traps ziet.

            if(rand() % 100 > (50 - mGame.player().perception())) {
                // discover traps
                const std::vector<dc::model::Trap*> &traps = mGame.player().room()->traps();
                if(!traps.empty()) {
                    for(dc::model::Trap *trap : traps) {
                        std::cout << "You notice a " << trap->name() << ".\n";
                        trap->discover();
                    }
                }

                // discover hidden items
                if(rand() % 100 > (50 - mGame.player().perception())) {
                    dc::model::Item *item = mItemLoader.createRandomItem();
                    std::cout << "You find a '" << item->name() << "' just laying around!" << std::endl;
                    mGame.player().inventory().add(*item);
                }
            }
        }

        InspectCommand *InspectCommand::create(Parameters parameters) {
            ServiceLocator &sl = ServiceLocator::getInstance();
            dc::model::Game &game = sl.resolve<dc::model::Game>();
            dc::game::ItemLoader &itemLoader = sl.resolve<dc::game::ItemLoader>();

            return new InspectCommand(game, itemLoader);
        }
    }
}
