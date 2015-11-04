#ifndef DUNGEONCRAWLER_USECOMMAND_H
#define DUNGEONCRAWLER_USECOMMAND_H

#include <string>
#include "command.h"

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace game {
        class UseCommand : public dc::game::Command {
        public:
            UseCommand(model::Player &player, const std::string itemName);

            virtual void execute() const override;
            virtual bool isAction() const;

            static UseCommand *create(Parameters parameters);

        private:
            dc::model::Player &mPlayer;
            std::string mItemName;
        };
    }
}

#endif //DUNGEONCRAWLER_USECOMMAND_H
