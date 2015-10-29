#ifndef DUNGEONCRAWLER_TRAPLOADER_H
#define DUNGEONCRAWLER_TRAPLOADER_H

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
		class TrapLoader
		{
			private:
				static bool trapsLoaded;
				std::vector<std::string> loadedTraps;

				void loadTraps();
				
			public:
				std::string getRandomTrap();

				TrapLoader(){}
				~TrapLoader()
				{
					trapsLoaded = false;
				}
		};
	}
}

#endif //DUNGEONCRAWLER_TRAPLOADER_H