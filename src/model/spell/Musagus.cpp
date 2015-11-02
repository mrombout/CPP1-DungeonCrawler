#include <vector>
#include "Musagus.h"
#include "item/Item.h"
#include "Inventory.h"
#include "util/Random.h"

namespace dc {
    namespace model {
        void Musagus::cast(dc::model::Character &character, dc::model::Game &game) const {
            dc::model::Inventory &inventory = character.inventory();
            std::vector<dc::model::Item*> items = inventory.items();
            dc::model::Item *item = items[Random::nextInt(0, items.size() - 1)];

            inventory.removeItem(*item);
            std::cout << "The " << item->name() << " in your inventory suddenly disintegrate. But hey! You healed 20 hp!" << std::endl;

            delete item;

            character.increaseHealth(20);
        }
    }
}
