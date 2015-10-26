#ifndef COMMAND_H
#define COMMAND_H

#include "command/Parameters.h"

namespace dc {
    namespace game {
        class GameLoop;
    }
}

namespace dc {
    namespace game {
        class Command {
        public:
            Command();

            virtual ~Command() { };

            virtual void execute() const = 0;
        };
    }
}

#endif // COMMAND_H
