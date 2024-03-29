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
			std::unordered_map<std::string, std::string> mobProps = ServiceLocator::getInstance().resolve<dc::game::MobLoader>().getRandomMob();

            return createMob(mobProps, level);
        }

        dc::model::Mob *MobGenerator::create(int id, unsigned int level) {
            std::unordered_map<std::string, std::string> mobProps = ServiceLocator::getInstance().resolve<dc::game::MobLoader>().getMob(id);

            return createMob(mobProps, level);
        }

        model::Mob *MobGenerator::createMob(std::unordered_map<std::string, std::string> &mobProps, unsigned int level) {
            dc::model::Mob *mob = new dc::model::Mob(Number::toInt(mobProps["id"]));

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
