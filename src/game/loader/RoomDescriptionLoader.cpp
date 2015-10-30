#include "RoomDescriptionLoader.h"

namespace dc {
	namespace game {
		bool RoomDescriptionLoader::roomsLoaded = false;

		void RoomDescriptionLoader::loadRoomDescriptions()
		{
			std::string line;

			std::ifstream file("assets/rooms.txt");
			if (file.is_open())
			{
				while (!file.eof())
				{
					getline(file, line);
					if (line[0] != '*' && !line.empty()){ // Mag niet starten met een * en mag niet leeg zijn
						loadedRooms.push_back(line);
					}
				}
				file.close();
			}
			else{
				std::cout << "Unable to open rooms.txt file." << std::endl;
			}

			roomsLoaded = true;
		}

		std::string RoomDescriptionLoader::getRandomRoom()
		{
			if (!roomsLoaded){
				loadRoomDescriptions();
			}

			int randomRoom = Random::nextInt(0, loadedRooms.size() - 1);

			if (loadedRooms.size() != 0){
				return loadedRooms[randomRoom];
			}
			else {
				return "";
			}
		}
	}
}