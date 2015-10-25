#ifndef COMMAND_H
#define COMMAND_H

#include "command/Parameters.h"

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
        virtual ~Command();

        virtual void execute() const = 0;

    private:
        Parameters *mParameters;
    };

}
}

#endif // COMMAND_H
