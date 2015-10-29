#include <stdlib.h>
#include "FileLoader.h"

using namespace dc::game;

namespace dc {
	namespace game {
		bool FileLoader::instanceFlag = false;
		bool FileLoader::mobsLoaded = false;
		bool FileLoader::roomsLoaded = false;
		bool FileLoader::trapsLoaded = false;
		FileLoader* FileLoader::single = NULL;
		FileLoader* FileLoader::getInstance()
		{
			if (!instanceFlag)
			{
				single = new FileLoader();
				instanceFlag = true;
				return single;
			}
			else
			{
				return single;
			}
		}

		void FileLoader::loadMobs()
		{
			std::string line;
			int lineCount = 0;

			std::ifstream file("E:/School/Software Architectuur/CPP1/Eindopdracht/CPP/src/textfiles/mobs.txt");
			if (file.is_open())
			{
				while (!file.eof())
				{
					getline(file, line);
					if (line[0] != '*' && !line.empty()){ // Mag niet starten met een * en mag niet leeg zijn
						std::vector<std::string> splittedWords;
						std::istringstream words(line);
						std::string word;

						while (getline(words, word, ';')) {
							splittedWords.push_back(trim(word));
						}
						
						if (splittedWords.size() >= 7){
							std::unordered_map<std::string, std::string> tempMap;
							tempMap.emplace("name", splittedWords[0]);
							tempMap.emplace("maxhealth", splittedWords[1]);
							tempMap.emplace("health", splittedWords[2]);
							tempMap.emplace("level", splittedWords[3]);
							tempMap.emplace("attack", splittedWords[4]);
							tempMap.emplace("defence", splittedWords[5]);
							tempMap.emplace("perception", splittedWords[6]);

							loadedMobs.emplace(lineCount, tempMap);
							lineCount++;
						}
						else {
							// Incorrect formaat
							std::cout << "Format of line " << lineCount + 1 << " in mobs.txt file is not correct." << std::endl;
						}
					}
				}
				file.close();
			}
			else{
				std::cout << "Unable to open mobs.txt file." << std::endl;
			}

			mobsLoaded = true;
		}

		std::unordered_map<std::string, std::string> FileLoader::getRandomMob()
		{
			if (!mobsLoaded){
				loadMobs();
			}

			int randomMob = Random::nextInt(0, loadedMobs.size() - 1);
			return loadedMobs[randomMob];
		}

		void FileLoader::loadRoomDescriptions()
		{
			std::string line;

			std::ifstream file("E:/School/Software Architectuur/CPP1/Eindopdracht/CPP/src/textfiles/rooms.txt");
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

		std::string FileLoader::getRandomRoom()
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

		void FileLoader::loadTraps()
		{
			std::string line;

			std::ifstream file("E:/School/Software Architectuur/CPP1/Eindopdracht/CPP/src/textfiles/traps.txt");
			if (file.is_open())
			{
				while (!file.eof())
				{
					getline(file, line);
					if (line[0] != '*' && !line.empty()){ // Mag niet starten met een * en mag niet leeg zijn
						loadedTraps.push_back(StrToUpper(line));
					}
				}
				file.close();
			}
			else{
				std::cout << "Unable to open traps.txt file." << std::endl;
			}

			trapsLoaded = true;
		}

		std::string FileLoader::getRandomTrap()
		{
			if (!trapsLoaded){
				loadTraps();
			}

			int randomTrap = Random::nextInt(0, loadedTraps.size() - 1);

			if (loadedTraps.size() != 0){
				return loadedTraps[randomTrap];
			}
			else {
				return "TrapType";
			}
		}

		std::vector<std::string> FileLoader::split(const std::string &text, char sep) {
			std::vector<std::string> tokens;
			int start = 0, end = 0;
			while ((end = text.find(sep, start)) != std::string::npos) {
				tokens.push_back(text.substr(start, end - start));
				start = end + 1;
			}
			tokens.push_back(text.substr(start));
			return tokens;
		}

		std::string FileLoader::trim(std::string &s) {
			while (s.compare(0, 1, " ") == 0)
				s.erase(s.begin()); // remove leading whitespaces
			while (s.size()>0 && s.compare(s.size() - 1, 1, " ") == 0)
				s.erase(s.end() - 1); // remove trailing whitespaces

			return s;
		}

		std::string FileLoader::StrToUpper(const std::string & Text)
		{
			std::string UppperCaseString;
			UppperCaseString.reserve(Text.size());
			for (std::string::const_iterator it = Text.begin(); it<Text.end(); ++it)
			{
				UppperCaseString.push_back(((0x60 < *it) && (*it < 0x7B)) ? (*it - static_cast<char>(0x20)) : *it);
			}
			return UppperCaseString;
		}
	}
}