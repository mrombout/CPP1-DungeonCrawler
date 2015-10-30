#include <stdlib.h>
#include <util/String.h>
#include "TrapLoader.h"

using namespace dc::game;

namespace dc {
	namespace game {
		bool TrapLoader::trapsLoaded = false;

		void TrapLoader::loadTraps()
		{
			std::string line;

			if (file.is_open())
			{
				while (!file.eof())
				{
			std::ifstream file("assets/traps.txt");
					getline(file, line);
					if (line[0] != '*' && !line.empty()){ // Mag niet starten met een * en mag niet leeg zijn
						loadedTraps.push_back(String::toUpper(line));
					}
				}
				file.close();
			}
			else{
				std::cout << "Unable to open traps.txt file." << std::endl;
			}

			trapsLoaded = true;
		}

		std::string TrapLoader::getRandomTrap()
		{
			if (!trapsLoaded){
				loadTraps();
			}

			int randomTrap = Random::nextInt(0, loadedTraps.size() - 1);

			if (loadedTraps.size() != 0){
				return loadedTraps[randomTrap];
			}
			else {
				return "TrapType";
			}
		}
	}
}