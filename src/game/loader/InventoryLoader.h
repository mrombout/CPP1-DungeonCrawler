#ifndef DUNGEONCRAWLER_INVENTORYLOADER_H
#define DUNGEONCRAWLER_INVENTORYLOADER_H

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
		class InventoryLoader
		{
			private:
				static bool inventoryLoaded;

				std::vector<std::string> loadedInventory;

				void loadInventory();
				
			public:
				std::vector<std::string> getInventory();

				InventoryLoader(){}
				~InventoryLoader()
				{
					inventoryLoaded = false;
				}
		};
	}
}

#endif //DUNGEONCRAWLER_INVENTORYLOADER_H