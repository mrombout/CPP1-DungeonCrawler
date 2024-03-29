#ifndef DUNGEONCRAWLER_COMBATCOMMANDMANAGER_H
#define DUNGEONCRAWLER_COMBATCOMMANDMANAGER_H

#include <vector>
#include <string>

namespace dc {
    namespace game {
        class Command;
        class CombatState;
        class AttackCommand;
    }
}

namespace dc {
    namespace game {
        class CombatCommandManager {
        public:
            CombatCommandManager(CombatState &combatState);

            dc::game::Command *create(std::string input) const;

        private:
            CombatState &mCombatState;
        };
    }
}

#endif //DUNGEONCRAWLER_COMBATCOMMANDMANAGER_H
