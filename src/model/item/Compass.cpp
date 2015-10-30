#include <iostream>
#include <list>
#include <sstream>
#include <iterator>
#include <util/console.h>
#include "util/DijkstraPathfinder.h"
#include "Compass.h"
#include "Floor.h"
#include "Room.h"
#include "Passage.h"
#include "Mob.h"

namespace dc {
    namespace model {
        Compass::Compass() :
            Item("Compass", "This compass is so smart, it can make bends!") {

        }

        void Compass::use(Character &character) {
            dc::model::Room *startRoom = character.room();
            dc::model::Floor *floor = startRoom->floor();
            dc::model::Room *endRoom = &floor->exitRoom();
            std::vector<dc::model::Mob*> mobsOnPath;
            int numTraps = 0;

            std::cout << csl::color(csl::WHITE) << "You take the compass out of your pocket. It vibrates in yours hands as it starts speaking to you: ";
            std::cout << "\n\n\"After 500 meters, turn ";

            // find path using dijkstra's algorithm
            std::list<dc::model::Passage*> path = DijkstraPathfinder::findPath(*floor, *startRoom, *endRoom);

            // announce directions
            dc::model::Room *currentRoom = startRoom;
            while(currentRoom != endRoom) {
                for(dc::model::Passage *passage : path) {
                    // output direction
                    dc::model::Passage *otherPassage = nullptr;
                    if(currentRoom->north() == passage) {
                        std::cout << "north";
                        otherPassage = currentRoom->north();
                    } else if(currentRoom->east() == passage) {
                        std::cout << "east";
                        otherPassage = currentRoom->east();
                    } else if(currentRoom->south() == passage) {
                        std::cout << "south";
                        otherPassage = currentRoom->south();
                    } else if(currentRoom->west() == passage) {
                        std::cout << "west";
                        otherPassage = currentRoom->west();
                    }

                    // update current room
                    currentRoom = &otherPassage->otherSide(*currentRoom);

                    // collect monsters
                    std::vector<dc::model::Mob*> mobs = currentRoom->mobs();
                    mobsOnPath.insert(mobsOnPath.end(), mobs.begin(), mobs.end());

                    numTraps += currentRoom->traps().size();

                    if(currentRoom != endRoom)
                        std::cout << " - ";
                }
            }

            // announce total monsters
            std::cout << "\"\n\n" << mobsOnPath.size() << " monster" << (mobsOnPath.size() > 1 ? "s" : "");
            if(mobsOnPath.size() > 0) {
                std::cout << " (";
                for(dc::model::Mob* mob : mobsOnPath) {
                    std::cout << mob->level() << " hp, ";
                }
                std::cout << mobsOnPath.back()->level() << " hp)\n";
            }

            // announce total traps
            std::cout << numTraps << " trap" << (numTraps > 1 ? "s" : "") << "\n\n" << std::endl;
        }

        Item *Compass::clone() const {
            return new Compass(*this);
        }
    }
}