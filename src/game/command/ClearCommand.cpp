#include <stdlib.h>
#include "ClearCommand.h"

namespace dc {
    namespace game {
        void game::ClearCommand::execute() const {
#if defined(__WIN32__) || defined(WIN32)
            system("cls");
#else
            system("clear");
#endif
        }

        ClearCommand *ClearCommand::create(Parameters parameters) {
            return new dc::game::ClearCommand();
        }

        bool ClearCommand::isAction() const {
            return false;
        }
    }
}