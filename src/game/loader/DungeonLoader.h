#ifndef DUNGEONCRAWLER_DUNGEONLOADER_H
#define DUNGEONCRAWLER_DUNGEONLOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace dc {
	namespace game {
		class DungeonLoader
		{
			public:
				DungeonLoader();
				~DungeonLoader();
				void LoadFromFile(std::string filePath);
		};
	}
}

#endif //DUNGEONCRAWLER_DUNGEONLOADER_H