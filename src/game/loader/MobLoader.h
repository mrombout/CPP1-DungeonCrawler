#ifndef DUNGEONCRAWLER_MOBLOADER_H
#define DUNGEONCRAWLER_MOBLOADER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <util/Random.h>
#include <sstream>

namespace dc {
    namespace game {
        class MobLoader {
        public:
            MobLoader();
            ~MobLoader();

            std::unordered_map<std::string, std::string> getRandomMob();

        private:
            void loadMobs();

        private:
            static bool mobsLoaded;
            std::unordered_map<int, std::unordered_map<std::string, std::string>> loadedMobs;
        };
    }
}

#endif //DUNGEONCRAWLER_MOBLOADER_H