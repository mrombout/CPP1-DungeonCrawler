#include <vector>
#include "MobGenerator.h"
#include "StringGenerator.h"

std::vector<std::vector<std::string>> mobNames {
        // adjective
        std::vector<std::string> {
                "Deluded ",
                "Intimidating ",
                "Ignored ",
                "Beautiful ",
                "Divine ",
                "Hellish "
        },

        // TODO: Names should be base monsters name read from file
        // names
        std::vector<std::string> {
                "Goblin",
                "Skeleton",
                "Ghoul",
                "Slime",
                "Vampire",
                "Ghost",
                "Werewolf",
                "Troll"
        }
};

namespace dc {
    namespace game {
        dc::model::Mob *MobGenerator::generate(unsigned int level) {
            dc::model::Mob *mob = new dc::model::Mob();

            // TODO: Load mob from files, with base levels
            mob->setName(StringGenerator::generateString(mobNames));
            mob->setMaxHealth(level * 2);
            mob->setHealth(level * 2);
            mob->setLevel(level);
            mob->setAttack(level);     // TODO: Set (base attack * level)
            mob->setDefence(level);    // TODO: Set (base defence * level)
            mob->setPerception(level); // TODO: Set (base perception * level)

            return mob;
        }
    }
}
