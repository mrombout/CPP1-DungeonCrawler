//
// Created by Robin de Mug on 27/10/15.
//

#ifndef DUNGEONCRAWLER_RESTCOMMAND_H
#define DUNGEONCRAWLER_RESTCOMMAND_H


#include <command.h>
#include <Player.h>

namespace dc {
    namespace game {
        class RestCommand : public dc::game::Command {
        public:
            RestCommand(dc::model::Player &player);

            virtual void execute() const override;
            virtual bool isAction() const;

            static RestCommand *create(Parameters parameters);

        private:
            dc::model::Player &mPlayer;
        };
    }
}


#endif //DUNGEONCRAWLER_RESTCOMMAND_H
