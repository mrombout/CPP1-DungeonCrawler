#ifndef DUNGEONCRAWLER_ROOMDESCRIPTIONLOADER_H
#define DUNGEONCRAWLER_ROOMDESCRIPTIONLOADER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <sstream>
#include "util/Random.h"

namespace dc {
	namespace game {
		class RoomDescriptionLoader
		{
			private:
				static bool roomsLoaded;
				std::vector<std::string> loadedRooms;
				
				void loadRoomDescriptions();
				
			public:
				std::string getRandomRoom();

				RoomDescriptionLoader(){}
				~RoomDescriptionLoader()
				{
					roomsLoaded = false;
				}
		};
	}
}

#endif //DUNGEONCRAWLER_ROOMDESCRIPTIONLOADER_H