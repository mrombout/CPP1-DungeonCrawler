#ifndef DUNGEONCRAWLER_SAVECOMMAND_H
#define DUNGEONCRAWLER_SAVECOMMAND_H

#include "command.h"
#include "Parameters.h"

namespace dc {
    namespace game {
        class SaveCommand : public dc::game::Command {
        public:
            SaveCommand(model::Player &player);

            virtual void execute() const;

            static SaveCommand *create(Parameters parameters);

        private:
            model::Player &mPlayer;
        };
    }
}


#endif //DUNGEONCRAWLER_SAVECOMMAND_H
