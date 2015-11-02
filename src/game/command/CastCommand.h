#ifndef DUNGEONCRAWLER_CASTCOMMAND_H
#define DUNGEONCRAWLER_CASTCOMMAND_H

#include "command.h"

namespace dc {
    namespace game {
        class CastCommand : public Command {
        public:
            CastCommand(std::string spellName, dc::model::Game &game, dc::model::Player &player);

            virtual void execute() const;
            virtual bool isAction() const;

            static CastCommand *create(Parameters &parameters);

        private:
            std::string mSpellName;
            dc::model::Game &mGame;
            dc::model::Player &mPlayer;
        };
    }
}

#endif //DUNGEONCRAWLER_CASTCOMMAND_H
