#ifndef DUNGEONCRAWLER_SAVECOMMAND_H
#define DUNGEONCRAWLER_SAVECOMMAND_H

#include "command.h"
#include "Parameters.h"

namespace dc {
    namespace game {
        class SaveCommand : public dc::game::Command {
        public:
            SaveCommand(model::Game &game);

            virtual void execute() const;

            static SaveCommand *create(Parameters parameters);

        private:
            model::Game &mGame;
        };
    }
}


#endif //DUNGEONCRAWLER_SAVECOMMAND_H
