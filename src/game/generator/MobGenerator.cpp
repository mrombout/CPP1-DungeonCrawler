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
			
			mob->setName(mobProps["name"]);
			mob->setMaxHealth(Number::toInt(mobProps["maxhealth"]) * level);
			mob->setHealth(mob->maxHealth());
			mob->setLevel(level);
			mob->setAttack(Number::toInt(mobProps["attack"]) * level);
			mob->setDefence(Number::toInt(mobProps["defence"]) * level);
			mob->setPerception(Number::toInt(mobProps["perception"]) * level);

            return mob;
        }
    }
}
