#ifndef COMMAND_H
#define COMMAND_H

#include "CommandParameters.h"

namespace dc {
    namespace engine {
        class GameLoop;
    }
}

namespace dc {
namespace engine {

    class Command
    {
    public:
        Command();

        virtual void execute(CommandParameters &parameters) const;
        virtual void execute(engine::GameLoop &game) const;
    };

}
}

#endif // COMMAND_H
