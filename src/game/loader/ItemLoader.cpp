#include <istream>
#include <fstream>
#include <util/Random.h>
#include "util/Number.h"
#include "util/String.h"
#include "ItemLoader.h"
#include "item/HealthPotion.h"
#include "item/ExperiencePotion.h"
#include "item/Sword.h"

namespace dc {
    namespace game {
        ItemLoader::ItemLoader() :
            mFactories({
               {"hp", &ItemLoader::createHealthPotion},
               {"xp", &ItemLoader::createExperiencePotion},
               {"sw", &ItemLoader::createSword}
            }) {

        }

        ItemLoader::~ItemLoader() {

        }

        dc::model::Item *ItemLoader::createRandomItem() {
            lazyLoadItems();

            if(rand() % 100 > 50) {
                return createRandomPotion();
            } else {
                return createRandomEquipable();
            }
        }

        dc::model::Potion *ItemLoader::createRandomPotion() {
            lazyLoadItems();

            return static_cast<dc::model::Potion*>(mPotions[Random::nextInt(0, mPotions.size() - 1)]->clone());
        }

        dc::model::Equipable *ItemLoader::createRandomEquipable() {
            lazyLoadItems();

            return static_cast<dc::model::Equipable*>(mEquipables[Random::nextInt(0, mEquipables.size() - 1)]->clone());
        }

        dc::model::Item *ItemLoader::createItem(unsigned int id) {
            lazyLoadItems();

            return mItems[id]->clone();
        }

        void ItemLoader::lazyLoadItems() {
            if(!mEquipables.empty() && !mPotions.empty())
                return;
            loadItems();
        }

        void ItemLoader::loadItems() {
            const std::string itemsFile{"assets/items.txt"};

            std::ifstream input{itemsFile};
            std::string line;

            while(getline(input, line)) {
                std::vector<std::string> p = String::split(line, ';');
                ItemFactoryMethod f = mFactories[p[0]];
                (this->*f)(p);
            }
        }

        void ItemLoader::createHealthPotion(std::vector<std::string> &input) {
            std::string description = "Heals ";
            description += Number::toInt(input[3]) + " health points";

            dc::model::HealthPotion *potion = new dc::model::HealthPotion(Number::toInt(input[1]), input[2], description, Number::toInt(input[3]));

            mPotions.push_back(potion);
            mItems[potion->id()] = potion;
        }

        void ItemLoader::createExperiencePotion(std::vector<std::string> &input) {
            std::string description = "Adds ";
            description += Number::toInt(input[3]) + " experience points";

            dc::model::ExperiencePotion *potion = new dc::model::ExperiencePotion(Number::toInt(input[1]), input[2], description, Number::toInt(input[3]));

            mPotions.push_back(potion);
            mItems[potion->id()] = potion;
        }

        void ItemLoader::createSword(std::vector<std::string> &input) {
            dc::model::Sword *sword = new dc::model::Sword(Number::toInt(input[1]), input[2], input[2], Number::toInt(input[3]));

            mEquipables.push_back(sword);
            mItems[sword->id()] = sword;
        }
    }
}