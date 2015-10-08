#include <exception/NotImplementedException.h>
#include "command.h"

namespace dc {
namespace engine {

    Command::Command()
    {

    }

    void Command::execute() const {
        throw NotImplementedException();
    }
}
}

