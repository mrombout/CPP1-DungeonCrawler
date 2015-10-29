#include <stdlib.h>
#include "FileLoader.h"

using namespace dc::game;

namespace dc {
	namespace game {
		bool FileLoader::instanceFlag = false;
		FileLoader* FileLoader::single = NULL;
		FileLoader* FileLoader::getInstance()
		{
			if (!instanceFlag)
			{
				single = new FileLoader();
				single->initialize();
				instanceFlag = true;
				return single;
			}
			else
			{
				return single;
			}
		}

		void FileLoader::initialize(){
			mobLoader = new MobLoader();
			inventoryLoader = new InventoryLoader();
			trapLoader = new TrapLoader();
			roomDescriptionLoader = new RoomDescriptionLoader();
		}

		MobLoader FileLoader::getMobLoader(){
			return *mobLoader;
		}

		InventoryLoader FileLoader::getInventoryLoader(){
			return *inventoryLoader;
		}

		TrapLoader FileLoader::getTrapLoader(){
			return *trapLoader;
		}

		RoomDescriptionLoader FileLoader::getRoomDescriptionLoader(){
			return *roomDescriptionLoader;
		}
	}
}