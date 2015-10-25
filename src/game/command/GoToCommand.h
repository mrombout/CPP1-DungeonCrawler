#include "command.h"

#ifndef DUNGEONCRAWLER_GOTOCOMMAND_H
#define DUNGEONCRAWLER_GOTOCOMMAND_H

namespace dc {
    namespace game {
        class GoToCommand: public engine::Command {
        public:
            GoToCommand(std::string heading, dc::model::Player &player, dc::model::Passage &passage);
            virtual void execute() const override;

            static GoToCommand *create(Parameters parameters);

        private:
            std::string mHeading;
            dc::model::Player &mPlayer;
            dc::model::Passage &mPassage;
        };
    }
}

#endif //DUNGEONCRAWLER_GOTOCOMMAND_H
