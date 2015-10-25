#include "command.h"

#ifndef DUNGEONCRAWLER_GOTOCOMMAND_H
#define DUNGEONCRAWLER_GOTOCOMMAND_H

namespace dc {
    namespace game {
        class GoToCommand: public engine::Command {
        private:
            std::vector<std::string> params;
        public:
            GoToCommand() { }
            virtual void execute() const override;

            static GoToCommand *create(Parameters parameters);
        };
    }
}

#endif //DUNGEONCRAWLER_GOTOCOMMAND_H
