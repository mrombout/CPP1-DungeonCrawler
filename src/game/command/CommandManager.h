#ifndef DUNGEONCRAWLER_COMMANDMANAGER_H
#define DUNGEONCRAWLER_COMMANDMANAGER_H

#include <string>
#include "command.h"

namespace dc {
    class Command;
}

namespace dc {
    class CommandManager {
    public:
        dc::game::Command *create(std::string name) const;
    };
}

#endif //DUNGEONCRAWLER_COMMANDMANAGER_H
