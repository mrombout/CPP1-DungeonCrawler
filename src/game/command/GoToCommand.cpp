//
// Created by Robin on 10/23/2015.
//

#include <iostream>
#include <Passage.h>
#include <Room.h>
#include "GoToCommand.h"

namespace dc {
    namespace game {
        void game::GoToCommand::execute(engine::CommandParameters &parameters) const {
            if (this->params.size() > 0) {
                std::string heading = params[0];

                model::Room *currentRoom = &parameters.player().room();
                model::Passage *passage = nullptr;

                if (heading == "north") {
                    passage = parameters.player().room().north();
                    model::Room *sideA = &passage->sideA();
                    model::Room *sideB = &passage->sideB();
                    parameters.player().setRoom((sideA == currentRoom) ? *sideB : *sideA);
                } else if (heading == "east") {

                } else if (heading == "south") {

                } else if (heading == "west") {

                } else {
                    std::cout << "Invalid direction, either use north, east, south or west" << std::endl;
                }
                return;
            } else {
                std::cout << "Could not determine the way to go without direction!" << std::endl;
            }
        }
    }
}