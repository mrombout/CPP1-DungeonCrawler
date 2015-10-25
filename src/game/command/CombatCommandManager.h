#ifndef DUNGEONCRAWLER_COMBATCOMMANDMANAGER_H
#define DUNGEONCRAWLER_COMBATCOMMANDMANAGER_H

#include <vector>
#include <string>
#include <command.h>

namespace dc {
    namespace engine {
        class Command;
    }
}

class CombatState;
class AttackCommand;

class CombatCommandManager {
public:
    CombatCommandManager(CombatState &combatState);

    dc::engine::Command *create(std::string input) const;

private:
    dc::engine::Command *createAttackCommand(std::vector<std::string> &vector) const;

    CombatState &mCombatState;
};

#endif //DUNGEONCRAWLER_COMBATCOMMANDMANAGER_H
