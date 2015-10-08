#include <exception/NotImplementedException.h>
#include "command.h"

namespace dc {
namespace engine {

    Command::Command()
    {

    }

    void Command::execute(engine::GameLoop &game) const {
        throw NotImplementedException();
    }

    void Command::execute(CommandParameters &parameters) const {

    }
}
}

