#include <queue>
#include <unordered_map>
#include <iostream>
#include "MapCommand.h"
#include "Room.h"
#include "Floor.h"
#include "Passage.h"

namespace dc {
	void game::MapCommand::execute(engine::CommandParameters &parameters) const {
		model::Room &room = parameters.player().room();

		render(room);
	}

	void game::MapCommand::render(model::Room &room) const {
		// create empty map
		int width = 16;
		int height = 16;

		char** mGrid = new char*[height];
		for (int i = 0; i < height; ++i) {
			mGrid[i] = new char[width];
			mGrid[i][width - 1] = mGrid[i][0];
			std::fill_n(mGrid[i], width, '.');
		}

		// start rendering to buffer
		std::unordered_map<model::Room*, bool> markedRooms;
		std::queue<model::Room*> queue;
		queue.push(&room);
		markedRooms[&room] = true;

		std::cout << "Render player room" << std::endl;

		while(!queue.empty()) {
			model::Room *currentRoom = queue.front();
			queue.pop();

			std::vector<model::Passage*> adjacantPassages = currentRoom->adjacantPassages();
			for(model::Passage *passage : adjacantPassages) {
				model::Room &adjacantRoom = passage->sideB();
				if(adjacantRoom.isVisited() && markedRooms.count(&adjacantRoom) == 0) {
					markedRooms[&adjacantRoom] = true;
					queue.push(currentRoom);
					std::cout << "Rendering: " + adjacantRoom.description() << std::endl;
				}
			}
		}

		// render to screen
		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				std::cout << mGrid[y][x];
			}
			std::cout << std::endl;
		}
	}
}