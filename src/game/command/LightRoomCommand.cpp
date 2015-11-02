#include <util/ServiceLocator.h>
#include <Game.h>
#include "LightRoomCommand.h"

namespace dc {
    namespace game {
        LightRoomCommand::LightRoomCommand(dc::model::Player &player) :
            mPlayer(player) {

        }

        void LightRoomCommand::execute() const {
            mPlayer.room()->lighRoom();
            std::cout << "You light the torches in the room." << std::endl;
        }

        bool LightRoomCommand::isAction() const {
            return true;
        }

        LightRoomCommand *LightRoomCommand::create(Parameters parameters) {
            return new LightRoomCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player());
        }
    }
}