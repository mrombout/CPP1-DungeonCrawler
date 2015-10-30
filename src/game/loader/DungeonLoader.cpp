#include <stdlib.h>
#include "DungeonLoader.h"
#include "Dungeon.h"

using namespace dc::game;

namespace dc {
	namespace game {
		DungeonLoader::DungeonLoader()
		{
		}


		DungeonLoader::~DungeonLoader()
		{
		}

		void DungeonLoader::LoadFromFile(std::string filePath){
			int count = 0;
			std::vector<std::string> logs;
			std::string line;

			std::cout << "Testing loading of file." << std::endl;
			std::ifstream dungeonFile(filePath);
			if (dungeonFile.is_open())
			{
				while (!dungeonFile.eof())
				{
					getline(dungeonFile, line);
					logs.at(count) = line;
					count++;
				}
				dungeonFile.close();
			}
			else{
				std::cout << "Unable to open file." << std::endl;
			}
			std::cout << "the log count is: " << count << std::endl;

		}
	}
}