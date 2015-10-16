#include "MobGenerator.h"

dc::model::Mob *MobGenerator::generate(unsigned int seed, unsigned int level) {
    dc::model::Mob *mob = new dc::model::Mob();

    mob->setName("Deluded Goblin");
    mob->setHealth(100 * level);
    mob->setLevel(level);

    return mob;
}
