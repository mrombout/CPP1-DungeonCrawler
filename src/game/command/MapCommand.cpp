#include <queue>
#include <unordered_map>
#include <iostream>
#include "MapCommand.h"
#include "Room.h"
#include "Floor.h"
#include "Passage.h"
#include <generator/Point.h>

namespace dc {
	void game::MapCommand::execute(engine::CommandParameters &parameters) const {
		model::Room &room = parameters.player().room();

		render(room);
	}

	void game::MapCommand::render(model::Room &room) const {
		// create empty map
		int width = 15;
		int height = 15;

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

		Point point(width / 2, height / 2);

		mGrid[point.y()][point.x()] = '@';

		while(!queue.empty()) {
			model::Room *currentRoom = queue.front();
			queue.pop();

			std::vector<model::Passage*> adjacantPassages = currentRoom->adjacantPassages();
			for(model::Passage *passage : adjacantPassages) {
				model::Room &adjacantRoom = passage->sideB();
				if(adjacantRoom.isVisited() && markedRooms.count(&adjacantRoom) == 0) {
					markedRooms[&adjacantRoom] = true;
					queue.push(currentRoom);

					switch(passage->direction()) {
						case model::Passage::North:
							point.up();
							mGrid[point.y()][point.x()] = '|';
							point.up();
							break;
						case model::Passage::East:
							point.right();
							mGrid[point.y()][point.x()] = '-';
							point.right();
							break;
						case model::Passage::South:
							point.down();
							mGrid[point.y()][point.x()] = '-';
							point.down();
							break;
						case model::Passage::West:
							point.left();
							mGrid[point.y()][point.x()] = '-';
							point.left();
							break;
						default: break;
					}

					mGrid[point.y()][point.x()] = 'N';
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