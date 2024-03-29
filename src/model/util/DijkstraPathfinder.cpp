#include <map>
#include <limits>
#include <functional>
#include <queue>
#include <list>
#include <iostream>
#include "DijkstraPathfinder.h"
#include "Room.h"
#include "Floor.h"
#include "Passage.h"

std::list<dc::model::Passage*> DijkstraPathfinder::findPath(dc::model::Floor &floor, dc::model::Room &startRoom, dc::model::Room &endRoom) {
    // create vertex set Q
    std::map<dc::model::Room*, dc::model::Room*> prev;
    std::map<dc::model::Room*, dc::model::Passage*> prevEdges;
    std::map<dc::model::Room*, unsigned int> dist;

    std::list<dc::model::Room*> Q;

    // for each vertex v in Graph
    for(std::vector<dc::model::Room*> row : floor.rooms()) {
        for(dc::model::Room* v : row) {
            if(!v)
                continue;

            dist[v] = std::numeric_limits<unsigned int>::max();
            prev[v] = nullptr;
            Q.push_back(v);
        }
    }

    // dist[source] = 0
    dist[&startRoom] = 0;

    // while Q is not empty
    while(!Q.empty()) {
        dc::model::Room *u = Q.front();
        for(dc::model::Room* room : Q) {
            if(dist[room] < dist[u])
                u = room;
        }
        Q.remove(u);

        for(dc::model::Passage *e : u->adjacantPassages()) {
            if(e == nullptr)
                continue;

            dc::model::Room &v = e->otherSide(*u);
            unsigned int alt = dist[u] + e->weight();
            if(alt < dist[&v]) {
                dist[&v] = alt;
                prev[&v] = u;
                prevEdges[&v] = e;
            }
        }
    }

    // find shortest path
    std::list<dc::model::Passage*> path;
    dc::model::Room* u = &endRoom;
    while(prev.find(u) != prev.end()) {
        if(prevEdges[u])
            path.push_front(prevEdges[u]);
        u = prev[u];
    }

    return path;
}
