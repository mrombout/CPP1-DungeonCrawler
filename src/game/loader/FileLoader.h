#ifndef DUNGEONCRAWLER_FILELOADER_H
#define DUNGEONCRAWLER_FILELOADER_H

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
		class FileLoader
		{
			private:
				static bool instanceFlag;
				static FileLoader *single;

				static bool mobsLoaded;
				static bool roomsLoaded;
				static bool trapsLoaded;
				static bool inventoryLoaded;

				std::unordered_map<int, std::unordered_map<std::string, std::string>> loadedMobs;
				std::vector<std::string> loadedRooms;
				std::vector<std::string> loadedTraps;
				std::vector<std::string> loadedInventory;

				std::vector<std::string> split(const std::string &text, char sep);
				std::string trim(std::string &s);
				std::string FileLoader::StrToUpper(const std::string & Text);

				FileLoader(){}
				void loadMobs();
				void loadTraps();
				void loadRoomDescriptions();
				void loadInventory();
				
			public:
				static FileLoader* getInstance();
				std::unordered_map<std::string, std::string> getRandomMob();
				std::string getRandomRoom();
				std::string getRandomTrap();
				std::vector<std::string> getInventory();

				~FileLoader()
				{
					instanceFlag = false;
					mobsLoaded = false;
				}
		};
	}
}

#endif //DUNGEONCRAWLER_FILELOADER_H