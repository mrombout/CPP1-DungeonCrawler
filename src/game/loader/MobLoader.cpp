#include <stdlib.h>
#include "util/console.h"
#include "util/String.h"
#include "exception/InvalidFormatException.h"
#include "MobLoader.h"

using namespace dc::game;

namespace dc {
    namespace game {
        MobLoader::MobLoader() {

        }

        MobLoader::~MobLoader() {

        }

        void MobLoader::loadMobs() {
            std::string line;
            int lineCount = 0;

            csl::log() << "LOAD - Loading Mobs" << std::endl;

            std::ifstream file("assets/mobs.txt");
            if (file.is_open()) {
                while (!file.eof()) {
                    getline(file, line);
                    if (line[0] != '*' && !line.empty()) { // Mag niet starten met een * en mag niet leeg zijn
                        std::vector<std::string> splittedWords;
                        std::istringstream words(line);
                        std::string word;

                        while (getline(words, word, ';')) {
                            splittedWords.push_back(String::trim(word));
                        }

                        if (splittedWords.size() >= 7) {
                            std::unordered_map<std::string, std::string> tempMap;
                            tempMap.emplace("name", splittedWords[0]);
                            tempMap.emplace("maxhealth", splittedWords[1]);
                            tempMap.emplace("health", splittedWords[2]);
                            tempMap.emplace("level", splittedWords[3]);
                            tempMap.emplace("attack", splittedWords[4]);
                            tempMap.emplace("defence", splittedWords[5]);
                            tempMap.emplace("perception", splittedWords[6]);

                            loadedMobs.emplace(lineCount, tempMap);
                            lineCount++;
                        } else {
                            std::stringstream ss;
                            ss << "Format of line '" << (lineCount + 1) << "' in mobs.txt file is not correct.";
                            throw new InvalidFormatException(ss.str());
                        }
                    }
                }
                file.close();
            }
            else {
                std::cout << "Unable to open mobs.txt file." << std::endl;
            }
        }

        std::unordered_map<std::string, std::string> MobLoader::getRandomMob() {
            if (loadedMobs.empty()) {
                loadMobs();
            }

            int randomMob = Random::nextInt(0, loadedMobs.size() - 1);
            return loadedMobs[randomMob];
        }
    }
}