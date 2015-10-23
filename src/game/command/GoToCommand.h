//
// Created by Robin on 10/23/2015.
//

#include <command.h>

#ifndef DUNGEONCRAWLER_GOTOCOMMAND_H
#define DUNGEONCRAWLER_GOTOCOMMAND_H


namespace dc {
    namespace game {
        class GoToCommand: public engine::Command {
        private:
            std::vector<std::string> params;
        public:
            GoToCommand(std::vector<std::string> &parameters) { this->params = parameters; }
            virtual void execute(engine::CommandParameters &parameters) const override;
        };
    }
}


#endif //DUNGEONCRAWLER_GOTOCOMMAND_H
