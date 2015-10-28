//
// Created by Robin de Mug on 28/10/15.
//

#ifndef DUNGEONCRAWLER_EQUIPCOMMAND_H
#define DUNGEONCRAWLER_EQUIPCOMMAND_H


#include <command.h>
#include <Player.h>

namespace dc {
    namespace game {
        class EquipCommand : public dc::game::Command {
        public:
            EquipCommand(model::Player &player, const std::string itemName);
            virtual void execute() const override;

            static EquipCommand *create(Parameters parameters);

        private:
            dc::model::Player &mPlayer;
            std::string mItemName;
        };
    }
}


#endif //DUNGEONCRAWLER_EQUIPCOMMAND_H
