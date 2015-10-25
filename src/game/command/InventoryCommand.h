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
        class InventoryCommand : public engine::Command {
        public:
            InventoryCommand(dc::model::Player &player);
            virtual void execute() const override;

            static InventoryCommand *create(Parameters parameters);

        private:
            dc::model::Player &mPlayer;
        };
    }
}


#endif //DUNGEONCRAWLER_INVENTORYCOMMAND_H
