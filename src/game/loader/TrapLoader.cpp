#include <stdlib.h>
#include "util/String.h"
#include "util/Number.h"
#include "TrapLoader.h"
#include "BearTrap.h"
#include "NearDeathTrap.h"
#include "RatTrap.h"
#include "MobCallTrap.h"
#include "TeleportTrap.h"

using namespace dc::game;

namespace dc {
	namespace game {
        TrapLoader::TrapLoader() {

        }

        TrapLoader::~TrapLoader() {

        }

		void TrapLoader::loadTraps() {
			std::string line;

			std::ifstream file("assets/traps.txt");
			if (file.is_open()) {
				while (!file.eof()) {
					getline(file, line);
					if (line[0] != '*' && !line.empty()) {
						std::vector<std::string> parts = String::split(line, ';');

                        std::string trapName = String::toUpper(parts[0]);
                        loadedTraps.push_back(trapName);
                        loadedTrapData[trapName] = new TrapData(trapName, Number::toInt(parts[1]));
					}
				}
				file.close();
			} else {
				std::cout << "Unable to open traps.txt file." << std::endl;
			}
		}

		dc::model::Trap *TrapLoader::getRandomTrap() {
			if (loadedTraps.empty())
				loadTraps();

			int randomTrap = Random::nextInt(0, loadedTraps.size() - 1);

			if (loadedTraps.size() != 0)
                return createTrap(loadedTraps[randomTrap]);
            return nullptr;
		}

        dc::model::Trap *TrapLoader::createTrap(const std::string &trapName) {
            if (trapName == dc::model::BearTrap::ID)
                return new dc::model::BearTrap(loadedTrapData[trapName]->value);
            if (trapName == dc::model::MobCallTrap::ID)
                return new dc::model::MobCallTrap();
            if (trapName == dc::model::NearDeathTrap::ID)
                return new dc::model::NearDeathTrap(loadedTrapData[trapName]->value);
            if (trapName == dc::model::RatTrap::ID)
                return new dc::model::RatTrap();
            if (trapName == dc::model::TeleportTrap::ID)
                return new dc::model::TeleportTrap();

            std::cout << "Sorry, we can't recognize the " + trapName + "." << std::endl;
        }
    }
}