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

#include "MobLoader.h"
#include "InventoryLoader.h"
#include "TrapLoader.h"
#include "RoomDescriptionLoader.h"

namespace dc {
	namespace game {
		class FileLoader
		{
			private:
				static bool instanceFlag;
				static FileLoader *single;

				FileLoader(){}

				MobLoader *mobLoader;
				InventoryLoader *inventoryLoader;
				TrapLoader *trapLoader;
				RoomDescriptionLoader *roomDescriptionLoader;

				void FileLoader::initialize();
				
			public:
				static FileLoader* getInstance();

				~FileLoader()
				{
					instanceFlag = false;
					delete mobLoader;
					delete inventoryLoader;
					delete trapLoader;
					delete roomDescriptionLoader;
				}

				MobLoader FileLoader::getMobLoader();
				InventoryLoader FileLoader::getInventoryLoader();
				TrapLoader FileLoader::getTrapLoader();
				RoomDescriptionLoader FileLoader::getRoomDescriptionLoader();
		};
	}
}

#endif //DUNGEONCRAWLER_FILELOADER_H