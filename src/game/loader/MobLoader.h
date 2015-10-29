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
		class MobLoader
		{
			private:
				static bool mobsLoaded;
				std::unordered_map<int, std::unordered_map<std::string, std::string>> loadedMobs;
				
				void loadMobs();
				
			public:
				std::unordered_map<std::string, std::string> getRandomMob();

				MobLoader(){}
				~MobLoader()
				{
					mobsLoaded = false;
				}
		};
	}
}

#endif //DUNGEONCRAWLER_MOBLOADER_H