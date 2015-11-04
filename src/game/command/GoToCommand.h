#ifndef DUNGEONCRAWLER_GOTOCOMMAND_H
#define DUNGEONCRAWLER_GOTOCOMMAND_H

#include "command.h"

namespace dc {
    namespace model {
        class Player;
        class Passage;
    }
}

namespace dc {
    namespace game {
        class GoToCommand: public game::Command {
        public:
            GoToCommand(std::string heading, dc::model::Player &player, dc::model::Passage &passage);

            virtual void execute() const override;
            virtual bool isAction() const;

            static GoToCommand *create(Parameters parameters);

        private:
            bool springTraps() const;

        private:
            std::string mHeading;
            dc::model::Player &mPlayer;
            dc::model::Passage &mPassage;
        };
    }
}

#endif //DUNGEONCRAWLER_GOTOCOMMAND_H
