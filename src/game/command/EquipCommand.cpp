#include <iostream>
#include "util/ServiceLocator.h"
#include "Game.h"
#include "EquipCommand.h"
#include "item/Item.h"
#include "item/Equipable.h"

namespace dc {
    namespace game {
        EquipCommand::EquipCommand(model::Player &player, const std::string itemName) :
                mPlayer(player),
                mItemName(itemName) {

        }

        void EquipCommand::execute() const {
            // look up item in inventory
            dc::model::Item *item = mPlayer.inventory().findItem(mItemName);
            if(item != nullptr) {
                dc::model::Equipable *equipable = dynamic_cast<dc::model::Equipable*>(item);
                if (equipable) {
                    std::cout << "Equipping " << item->name() << "..." << std::endl;
                    mPlayer.setWeapon((dc::model::Equipable *) item);
                    std::cout << "Equiped!" << std::endl;
                } else {
                    std::cout << "I can't equip that!" << std::endl;
                }
            } else {
                std::cout << "I don't know what " << mItemName << " is" << std::endl;
            }
        }

        EquipCommand *EquipCommand::create(Parameters parameters) {
            if(parameters.num() != 1) {
                std::cout << "What should I equip?" << std::endl;
                return nullptr;
            }

            return new EquipCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player(),
                                  parameters.param(0));
        }

        bool EquipCommand::isAction() const {
            return false;
        }
    }
}