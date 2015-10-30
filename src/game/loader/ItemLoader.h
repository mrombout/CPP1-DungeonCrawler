#ifndef DUNGEONCRAWLER_ITEMLOADER_H
#define DUNGEONCRAWLER_ITEMLOADER_H

#include <map>
#include <functional>
#include "item/Equipable.h"
#include "item/Grenade.h"
#include "item/Potion.h"
#include "item/Item.h"

namespace dc {
    namespace game {
        class ItemLoader;

        typedef void(ItemLoader::*ItemFactoryMethod)(std::vector<std::string>&);

        class ItemLoader {
        public:
            ItemLoader();

            dc::model::Item *createRandomItem();
            dc::model::Potion *createRandomPotion();
            dc::model::Equipable *createRandomEquipable();

        private:
            void lazyLoadItems();
            void loadItems();

            void createHealthPotion(std::vector<std::string> &input);
            void createExperiencePotion(std::vector<std::string> &input);
            void createSword(std::vector<std::string> &input);

        private:
            std::map<std::string, ItemFactoryMethod> mFactories;

            std::vector<dc::model::Potion*> mPotions;
            std::vector<dc::model::Equipable*> mEquipables;
        };
    }
}

#endif //DUNGEONCRAWLER_ITEMLOADER_H
