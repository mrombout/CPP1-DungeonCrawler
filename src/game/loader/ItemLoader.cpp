#include <istream>
#include <fstream>
#include <util/Random.h>
#include "util/Number.h"
#include "util/String.h"
#include "ItemLoader.h"
#include "item/HealthPotion.h"
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
            for(auto it = mPotions.begin(); it != mPotions.end(); ++it)
                delete *it;
            for(auto it = mEquipables.begin(); it != mEquipables.end(); ++it)
                delete *it;
        }

        dc::model::Item &ItemLoader::createRandomItem() {
            lazyLoadItems();

            if(rand() % 100 > 50) {
                return createRandomPotion();
            } else {
                return createRandomEquipable();
            }
        }

        dc::model::Potion &ItemLoader::createRandomPotion() {
            lazyLoadItems();

            return *mPotions[Random::nextInt(0, mPotions.size() - 1)];
        }

        dc::model::Equipable &ItemLoader::createRandomEquipable() {
            lazyLoadItems();

            return *mEquipables[Random::nextInt(0, mEquipables.size() - 1)];
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
            description += Number::toInt(input[2]) + " health points";
            mPotions.push_back(new dc::model::HealthPotion(input[1], description, Number::toInt(input[2])));
        }

        void ItemLoader::createExperiencePotion(std::vector<std::string> &input) {
            std::string description = "Adds ";
            description += Number::toInt(input[2]) + " experience points";
            mPotions.push_back(new dc::model::HealthPotion(input[1], description, Number::toInt(input[2])));
        }

        void ItemLoader::createSword(std::vector<std::string> &input) {
            dc::model::Sword *sword = new dc::model::Sword(input[1], input[1], Number::toInt(input[2]));
            mEquipables.push_back(sword);
        }
    }
}