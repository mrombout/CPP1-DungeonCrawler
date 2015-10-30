#include <iostream>
#include <map>
#include <queue>
#include <fixture/Ladder.h>
#include "Talisman.h"
#include "Room.h"
#include "Passage.h"

namespace dc {
    namespace model {
        Talisman::Talisman()
                : Item(-1, "Talisman", "My grandmother gave this to me. She used it to find the bathroom.") {

        }

        void Talisman::use(Character &character) {
            dc::model::Room* startRoom = character.room();

            std::map<Room*, int> distances;
            std::queue<Room*> queue;

            distances[startRoom] = 0;
            queue.push(startRoom);

            if(isLadderUp(distances, *startRoom))
                return;

            while(!queue.empty()) {
                Room *currentRoom = queue.front();
                queue.pop();

                for(Passage* passage : currentRoom->adjacantPassages()) {
                    if(!passage)
                        continue;

                    Room &otherRoom = passage->otherSide(*currentRoom);
                    if(distances.find(&otherRoom) == distances.end()) {
                        distances[&otherRoom] = distances[currentRoom] + 1;
                        if(isLadderUp(distances, otherRoom))
                            return;
                        queue.push(&otherRoom);
                    }
                }
            }

            std::cout << "The Talisman remains awfully silent." << std::endl;
        }

        bool Talisman::isLadderUp(std::map<Room*, int> &distances, Room &room) {
            dc::model::Ladder *ladder = dynamic_cast<dc::model::Ladder*>(room.inventory().findItem("Ladder"));
            if(ladder && ladder->direction() == dc::model::Ladder::Direction::UP) {
                std::cout << "The Talisman glows as it whispers in your ears, '" << distances[&room] << " rooms away, the stairs upwards are. Yes, hmmmm.'." << std::endl;
                return true;
            }

            return false;
        }

        Item *Talisman::clone() const {
            return new Talisman(*this);
        }
    }
}
