#ifndef DUNGEONCRAWLER_LIGHTROOMCOMMAND_H
#define DUNGEONCRAWLER_LIGHTROOMCOMMAND_H

#include <Player.h>
#include "command.h"

namespace dc {
    namespace game {
        class LightRoomCommand : public Command {
        public:
            LightRoomCommand(dc::model::Player &player);

            virtual bool isAction() const;
            virtual void execute() const;

            static LightRoomCommand *create(Parameters parameters);

        private:
            dc::model::Player &mPlayer;
        };
    }
}

#endif //DUNGEONCRAWLER_LIGHTROOMCOMMAND_H
