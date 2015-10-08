#ifndef COMMAND_H
#define COMMAND_H

#include "CommandParameters.h"

namespace dc {
namespace engine {

    class Command
    {
    public:
        Command();
        virtual void execute(CommandParameters &parameters) const = 0;
        virtual void execute() const;
    };

}
}

#endif // COMMAND_H
