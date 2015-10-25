#include <exception/NotImplementedException.h>
#include "command.h"

namespace dc {
    namespace engine {

        Command::Command() {

        }

        Command::~Command() {
            delete mParameters;
        }
    }
}

