#ifndef DUNGEONCRAWLER_ROOMDESCRIPTIONLOADER_H
#define DUNGEONCRAWLER_ROOMDESCRIPTIONLOADER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <sstream>
#include "util/Random.h"

namespace dc {
    namespace game {
        class RoomDescriptionLoader {
        public:
            RoomDescriptionLoader();
            ~RoomDescriptionLoader();

            std::string getRandomRoom();

        private:
            void loadRoomDescriptions();

        private:
            std::vector<std::vector<std::string>> loadedRooms;
        };
    }
}

#endif //DUNGEONCRAWLER_ROOMDESCRIPTIONLOADER_H