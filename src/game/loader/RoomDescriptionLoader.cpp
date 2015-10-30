#include <generator/StringGenerator.h>
#include "RoomDescriptionLoader.h"

namespace dc {
	namespace game {
		RoomDescriptionLoader::RoomDescriptionLoader() {

        }

		RoomDescriptionLoader::~RoomDescriptionLoader() {

		}

		void RoomDescriptionLoader::loadRoomDescriptions() {
			std::string line;

            std::unordered_map<char, std::vector<std::string>> roomTypes;
            roomTypes.insert({'s', {}});
            roomTypes.insert({'p', {}});
            roomTypes.insert({'m', {}});
            roomTypes.insert({'f', {}});

			std::ifstream file("assets/rooms.txt");
			if (file.is_open()) {
				while (!file.eof()) {
					getline(file, line);
					if (line[0] != '*' && !line.empty()){ // Mag niet starten met een * en mag niet leeg zijn
                        char type = line[0];
                        line.erase(0, 2);
                        std::vector<std::string> &v = roomTypes[type];
                        v.push_back(line);
					}
				}
				file.close();

                loadedRooms.push_back(roomTypes['s']);
                loadedRooms.push_back(roomTypes['p']);
                loadedRooms.push_back(roomTypes['m']);
                loadedRooms.push_back(roomTypes['f']);
			} else {
				std::cout << "Unable to open rooms.txt file." << std::endl;
			}
		}

		std::string RoomDescriptionLoader::getRandomRoom() {
			if (loadedRooms.empty()) {
				loadRoomDescriptions();
			}

            return StringGenerator::generateString(loadedRooms);
		}
	}
}