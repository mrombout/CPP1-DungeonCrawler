#include <vector>
#include "util/Number.h"
#include "util/ServiceLocator.h"
#include "loader/MobLoader.h"
#include "Mob.h"
#include "MobGenerator.h"
#include "StringGenerator.h"

namespace dc {
    namespace game {
        dc::model::Mob *MobGenerator::generate(unsigned int level) {
            dc::model::Mob *mob = new dc::model::Mob();

			std::unordered_map<std::string, std::string> mobProps = ServiceLocator::getInstance().resolve<dc::game::MobLoader>().getRandomMob();

            // TODO: Load mob from files, with base levels
			mob->setName(mobProps["name"]);
			mob->setMaxHealth(Number::toInt(mobProps["maxhealth"]));
			mob->setHealth(Number::toInt(mobProps["health"]));
			mob->setLevel(Number::toInt(mobProps["level"]));
			mob->setAttack(Number::toInt(mobProps["attack"]));     // TODO: Set (base attack * level)
			mob->setDefence(Number::toInt(mobProps["defence"]));    // TODO: Set (base defence * level)
			mob->setPerception(Number::toInt(mobProps["perception"])); // TODO: Set (base perception * level)

            return mob;
        }
    }
}
