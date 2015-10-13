//
// Created by Robin de Mug on 10/12/15.
//

#ifndef DUNGEONCRAWLER_INVENTORYCOMMAND_H
#define DUNGEONCRAWLER_INVENTORYCOMMAND_H

#include <command.h>

namespace dc {
    namespace game {
        class InventoryCommand : public engine::Command {
            virtual void execute(engine::CommandParameters &parameters) const override;
        };
    }
}


#endif //DUNGEONCRAWLER_INVENTORYCOMMAND_H
