#ifndef DUNGEONCRAWLER_NULLCOMMAND_H
#define DUNGEONCRAWLER_NULLCOMMAND_H

#include <command.h>

namespace dc {
    namespace game {
        class NullCommand : public engine::Command {
        public:
            virtual void execute() const;
        };
    }
}


#endif //DUNGEONCRAWLER_NULLCOMMAND_H
