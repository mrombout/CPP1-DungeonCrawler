#ifndef DUNGEONCRAWLER_TRAPLOADER_H
#define DUNGEONCRAWLER_TRAPLOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <unordered_map>
#include "util/Random.h"
#include "Trap.h"

namespace dc {
    namespace game {
        class TrapLoader {
        public:
            TrapLoader();
            ~TrapLoader();

            dc::model::Trap *getRandomTrap();
            dc::model::Trap *createTrap(const std::string &trapName);

        private:
            void loadTraps();

        private:
            static bool trapsLoaded;
            std::vector<std::string> loadedTraps;
        };
    }
}

#endif //DUNGEONCRAWLER_TRAPLOADER_H