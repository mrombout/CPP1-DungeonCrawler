#include <iostream>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <util/console.h>
#include "DisjointNode.h"
#include "Room.h"
#include "Grenade.h"
#include "Floor.h"
#include "Passage.h"
#include "Mob.h"
#include "util/Random.h"

namespace dc {
    namespace model {
        struct PassageComparer {
            bool operator()(Passage *a, Passage *b) {
                return a->weight() < b->weight();
            }
        };

        Grenade::Grenade() : Item(0, "Grenade", "A hand grenade, this will kill everything in the room and destroy half of the dungeon, except you.") { }

        void Grenade::use(Character &character) {
            Room *startRoom = character.room();
            Floor *floor = startRoom->floor();

            // explode
            if(!explode(floor, startRoom)) {
                std::cout << "You don't think that's a good idea right now." << std::endl;
                return;
            }

            std::cout << csl::color(csl::WHITE)
            << "The massive explosion is followed by a bright flash of octarine. When your vision finally returns you see that all the baddies are gone." << std::endl;

            // kill mobs
            for(Mob *mob : startRoom->mobs()) {
                mob->kill();
            }

            // remove grenade
            character.inventory().removeItem(*this);
            delete this;
        }

        bool Grenade::explode(Floor *floor, Room *startRoom) {
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

                        if(std::find(S.begin(), S.end(), passage) == S.end() && !passage->isCollapsed())
                            S.push_back(passage);
                    }
                }
            }
            std::sort(S.begin(), S.end(), PassageComparer());

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
			int collapsedPassages = 0;
			std::queue<Room*> queue;
			int passagesToCollapse = Random::nextInt(10, 15);

			queue.push(startRoom);

			while (!queue.empty()) {
				Room *currentRoom = queue.front();
				queue.pop();

				for (Passage* passage : currentRoom->adjacantPassages()) {
					if (!passage)
						continue;

					if (collapsedPassages >= passagesToCollapse)
						break;

					Room &otherRoom = passage->otherSide(*currentRoom);
					queue.push(&otherRoom);
					
					if (std::find(A.begin(), A.end(), passage) == A.end() && !passage->isCollapsed()) {
						passage->setCollapsed(true);
						collapsedPassages++;
					}
				}
			}

            return collapsedPassages > 0;
        }

        Item *Grenade::clone() const {
            return new Grenade(*this);
        }
    }
}
