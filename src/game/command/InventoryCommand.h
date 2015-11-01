#ifndef DUNGEONCRAWLER_INVENTORYCOMMAND_H
#define DUNGEONCRAWLER_INVENTORYCOMMAND_H

#include "command.h"

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace game {
        class InventoryCommand : public game::Command {
        public:
            InventoryCommand(dc::model::Player &player);

            virtual void execute() const override;
            virtual bool isAction() const;

            static InventoryCommand *create(Parameters parameters);

        private:
            dc::model::Player &mPlayer;
        };
    }
}


#endif //DUNGEONCRAWLER_INVENTORYCOMMAND_H
