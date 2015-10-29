#include <vector>
#include "Mob.h"
#include "MobGenerator.h"
#include "StringGenerator.h"

namespace dc {
    namespace game {
        dc::model::Mob *MobGenerator::generate(unsigned int level) {
            dc::model::Mob *mob = new dc::model::Mob();

			std::unordered_map<std::string, std::string> mobProps = FileLoader::getInstance()->getRandomMob();

            // TODO: Load mob from files, with base levels
			mob->setName(mobProps["name"]);
			mob->setMaxHealth(std::stoi(mobProps["maxhealth"]));
			mob->setHealth(std::stoi(mobProps["health"]));
			mob->setLevel(std::stoi(mobProps["level"]));
			mob->setAttack(std::stoi(mobProps["attack"]));     // TODO: Set (base attack * level)
			mob->setDefence(std::stoi(mobProps["defence"]));    // TODO: Set (base defence * level)
			mob->setPerception(std::stoi(mobProps["perception"])); // TODO: Set (base perception * level)

            return mob;
        }
    }
}
