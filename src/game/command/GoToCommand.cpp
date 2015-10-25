//
// Created by Robin on 10/23/2015.
//

#include <iostream>
#include <Passage.h>
#include <Room.h>
#include "GoToCommand.h"

namespace dc {
    namespace game {
        void game::GoToCommand::execute() const {
            /*
            if (this->params.size() > 0) {
                std::string heading = params[0];

                model::Room *currentRoom = &parameters.player().room();
                model::Passage *passage = nullptr;

                bool _continue = true;
                if (heading == "north") {
                    passage = parameters.player().room().north();
                    if (passage == nullptr) {
                        std::cout << "You cannot move to the North" << std::endl;
                        _continue = false;
                    }
                } else if (heading == "east") {
                    passage = parameters.player().room().east();
                    if (passage == nullptr) {
                        std::cout << "You cannot move to the East" << std::endl;
                        _continue = false;
                    }
                } else if (heading == "south") {
                    passage = parameters.player().room().south();
                    if (passage == nullptr) {
                        std::cout << "You cannot move to the South" << std::endl;
                        _continue = false;
                    }
                } else if (heading == "west") {
                    passage = parameters.player().room().west();
                    if (passage == nullptr) {
                        std::cout << "You cannot move to the West" << std::endl;
                        _continue = false;
                    }
                } else {
                    std::cout << "Invalid direction, either use north, east, south or west" << std::endl;
                }

                if (_continue) {
                    model::Room *sideA = &passage->sideA();
                    model::Room *sideB = &passage->sideB();
                    parameters.player().setRoom((sideA == currentRoom) ? *sideB : *sideA);
                    std::cout << "You went to the next Room (" << heading << ")" << std::endl;
                }

                return;
            } else {
                std::cout << "Could not determine the way to go without direction!" << std::endl;
            }
            */
        }

        GoToCommand *GoToCommand::create(Parameters parameters) {
            return new dc::game::GoToCommand();
        }
    }
}