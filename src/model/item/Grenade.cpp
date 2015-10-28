#include <iostream>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include "DisjointNode.h"
#include "Room.h"
#include "Grenade.h"
#include "Floor.h"
#include "Passage.h"
#include "Mob.h"

namespace dc {
    namespace model {
        Grenade::Grenade() : Item("Grenade", "A hand grenade, this will kill everything in the room and destroy half of the dungeon, except you.") { }

        void Grenade::use(Character &character) {
            Room *startRoom = character.room();
            Floor *floor = startRoom->floor();

            // explode
            explode(floor);

            // kill mobs
            for(Mob *mob : startRoom->mobs()) {
                mob->kill();
            }

            // remove grenade
            character.inventory().removeItem(*this);
        }

        void Grenade::explode(Floor *floor) {
            // initialize
            std::vector<Passage*> A;
            std::vector<Passage*> S;
            std::map<Room*, DisjointNode<Room*>*> F;

            for(std::vector<Room*> row : floor->rooms()) {
                for(Room* room : row) {
                    if(!room)
                        continue;

                    // create forest
                    DisjointNode<Room*> *v = new DisjointNode<Room*>(room);
                    F[room] = v;

                    // collect passages
                    for(Passage *passage : room->adjacantPassages()) {
                        if(!passage)
                            continue;

                        if(std::find(S.begin(), S.end(), passage) == S.end())
                            S.push_back(passage);
                    }
                }
            }

            // build MST
            for(Passage *uv : S) {
                Room &u = uv->sideA();
                Room &v = uv->sideB();
                if(F[&u]->find() != F[&v]->find()) {
                    A.push_back(uv);
                    F[&u]->unionMerge(F[&v]);
                }
            }

            // collapse passages
            for(std::vector<Room*> row : floor->rooms()) {
                for(Room* room : row) {
                    if(!room)
                        continue;

                    for(Passage *passage : room->adjacantPassages()) {
                        if(!passage)
                            continue;

                        if(std::find(A.begin(), A.end(), passage) == A.end()) {
                            passage->setCollapsed(true);
                        }
                    }
                }
            }
        }
    }
}
