#ifndef SAYACTION_H
#define SAYACTION_H

#include "action.h"

namespace dc {
namespace game {

    class SayAction : public Action
    {
    public:
        SayAction();

    public:
        void execute() const;
    };

}
}

#endif // SAYACTION_H
