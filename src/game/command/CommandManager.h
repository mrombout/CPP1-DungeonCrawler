#ifndef DUNGEONCRAWLER_COMMANDMANAGER_H
#define DUNGEONCRAWLER_COMMANDMANAGER_H

#include <string>

namespace dc {
    namespace engine {
        class Command;
    }
}

namespace dc {
    namespace game {
        class CommandManager {
        public:
            engine::Command *create(std::string name) const;
        };
    }
}

#endif //DUNGEONCRAWLER_COMMANDMANAGER_H
