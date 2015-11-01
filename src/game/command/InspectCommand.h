#ifndef DUNGEONCRAWLER_INSPECTCOMMAND_H
#define DUNGEONCRAWLER_INSPECTCOMMAND_H

#include "loader/ItemLoader.h"
#include "command.h"

namespace dc {
    namespace model {
        class Game;
    }
}

namespace dc {
    namespace game {
        class InspectCommand : public dc::game::Command {
        public:
            InspectCommand(dc::model::Game &game, dc::game::ItemLoader &itemLoader);
            virtual void execute() const override;

            static InspectCommand *create(Parameters parameters);

        private:
            dc::model::Game &mGame;
            dc::game::ItemLoader &mItemLoader;
        };
    }
}

#endif //DUNGEONCRAWLER_INSPECTCOMMAND_H
