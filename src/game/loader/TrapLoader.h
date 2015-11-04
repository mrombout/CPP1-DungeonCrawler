#ifndef DUNGEONCRAWLER_TRAPLOADER_H
#define DUNGEONCRAWLER_TRAPLOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <map>
#include "util/Random.h"
#include "Trap.h"

namespace dc {
    namespace game {
        class TrapLoader {
        public:
            struct TrapData {
                TrapData() {

                }
                
                TrapData(std::string name, int value) :
                        name(name),
                        value(value) {

                }

                std::string name;
                int value;
            };

            TrapLoader();
            ~TrapLoader();

            dc::model::Trap *getRandomTrap();
            dc::model::Trap *createTrap(const std::string &trapName);

        private:
            void loadTraps();

        private:
            static bool trapsLoaded;
            std::vector<std::string> loadedTraps;
            std::map<std::string, TrapData> loadedTrapData;
        };
    }
}

#endif //DUNGEONCRAWLER_TRAPLOADER_H