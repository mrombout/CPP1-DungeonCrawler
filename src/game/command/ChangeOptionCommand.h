#ifndef DUNGEONCRAWLER_CHANGEOPTIONCOMMAND_H
#define DUNGEONCRAWLER_CHANGEOPTIONCOMMAND_H

#include "command.h"

namespace dc {
    namespace game {
        class ChangeOptionCommand : public Command {
        public:
            ChangeOptionCommand(std::string mName, std::string mValue);

            virtual void execute() const;
            virtual bool isAction() const;

        private:
            std::string mName;
            std::string mValue;
        };
    }
}

#endif //DUNGEONCRAWLER_CHANGEOPTIONCOMMAND_H
