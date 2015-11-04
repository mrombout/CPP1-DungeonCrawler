#ifndef DUNGEONCRAWLER_CLEARCOMMAND_H
#define DUNGEONCRAWLER_CLEARCOMMAND_H

#include <command.h>

namespace dc {
    namespace game {
        class ClearCommand : public game::Command {
        public:
            virtual void execute() const override;
            virtual bool isAction() const;

            static ClearCommand *create(Parameters parameters);
        };
    }
}

#endif //DUNGEONCRAWLER_CLEARCOMMAND_H
