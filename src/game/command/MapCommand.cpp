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
		// create buffer
		int width = room.floor()->width() * 2 + 3;
		int height = room.floor()->height() * 2 + 3;

		char ** mGrid = new char*[height];
		for(int i = 0; i < height; ++i) {
			mGrid[i] = new char[width];
			mGrid[i][width - 1] = mGrid[i][0];
			std::fill_n(mGrid[i], width, ' ');
		}

		// render to buffer
		std::unordered_map<model::Room*, bool> markedRooms;
		std::queue<model::Room*> queue;

		markedRooms[&room] = true;
		queue.push(&room);

		int i = 0;
		while(!queue.empty()) {
			model::Room *currentRoom = queue.front();
			queue.pop();

			std::vector<model::Passage*> passages = currentRoom->adjacantPassages();
			for(model::Passage *passage : passages) {
				if(!passage)
					continue;

				model::Room &otherRoom = passage->sideB();

				drawPassage(mGrid, passage);

				if(markedRooms.count(&otherRoom) == 0 && otherRoom.isVisited()) {
					markedRooms[&otherRoom] = true;
					queue.push(&otherRoom);

					Point position = otherRoom.position();
					mGrid[(position.x() + 1) * 2][(position.y() + 1) * 2] = 'R';
					i++;
				}
			}
		}

		mGrid[(room.position().x() + 1) * 2][(room.position().y() + 1) * 2] = '@';

		std::cout << "Drawn" << i << "Rooms" << std::endl;

		// render to screen
		for(int y = 0; y < height; ++y) {
			for(int x = 0; x < width; ++x) {
				std::cout << mGrid[y][x];
			}
			std::cout << std::endl;
		}
	}

	void game::MapCommand::drawPassage(char **grid, model::Passage *passage) const {
		model::Room &aRoom = passage->sideA();
		Point aPosition = aRoom.position();

		model::Room &bRoom = passage->sideB();
		Point bPosition = bRoom.position();

		if(bPosition.y() < aPosition.y()) {
			// north
			grid[(aPosition.y() + 1) * 2 - 1][(aPosition.x() + 1) * 2] = '|';
		} else if(bPosition.y() > aPosition.y()) {
			// south
			grid[(aPosition.y() + 1) * 2 + 1] [(aPosition.x() + 1) * 2] = '|';
		} else if(bPosition.x() > aPosition.x()) {
			// east
			grid[(aPosition.y() + 1) * 2][(aPosition.x() + 1) * 2 + 1] = '-';
		} else if(bPosition.x() < aPosition.x()) {
			// west
			grid[(aPosition.y() + 1) * 2][(aPosition.x() + 1) * 2 - 1] = '-';
		}
	}
}