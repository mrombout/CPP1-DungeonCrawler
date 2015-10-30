#include <stdlib.h>
#include <util/String.h>
#include "InventoryLoader.h"

using namespace dc::game;

namespace dc {
	namespace game {
		bool InventoryLoader::inventoryLoaded = false;
		
		void InventoryLoader::loadInventory()
		{
			std::string line;

			std::ifstream file("assets/inventory.txt");
			if (file.is_open())
			{
				while (!file.eof())
				{
					getline(file, line);
					if (line[0] != '*' && !line.empty()){ // Mag niet starten met een * en mag niet leeg zijn
						loadedInventory.push_back(String::toUpper(line));
					}
				}
				file.close();
			}
			else{
				std::cout << "Unable to open inventory.txt file." << std::endl;
			}

			inventoryLoaded = true;
		}

		std::vector<std::string> InventoryLoader::getInventory(){
			if (!inventoryLoaded){
				loadInventory();
			}

			return loadedInventory;
		}
	}
}