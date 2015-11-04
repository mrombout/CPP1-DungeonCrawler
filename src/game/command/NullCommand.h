#ifndef DUNGEONCRAWLER_NULLCOMMAND_H
#define DUNGEONCRAWLER_NULLCOMMAND_H

#include "command.h"

namespace dc {
    namespace game {
        class NullCommand : public game::Command {
        public:
            virtual void execute() const;
            virtual bool isAction() const;

            static NullCommand *create(Parameters parameters);
        };
    }
}

#endif //DUNGEONCRAWLER_NULLCOMMAND_H
