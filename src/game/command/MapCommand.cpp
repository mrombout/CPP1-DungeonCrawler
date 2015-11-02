#include <queue>
#include <unordered_map>
#include <iostream>
#include "MapCommand.h"
#include "Game.h"
#include "Floor.h"
#include "Passage.h"
#include "Player.h"
#include "Parameters.h"
#include "util/ServiceLocator.h"
#include "util/console.h"

namespace dc {
	game::MapCommand::MapCommand(dc::model::Player &player, bool cheat) :
		mPlayer(player),
		mCheat(cheat),
        mZoomFactor(cheat ? 4 : 2) {

	}

	void game::MapCommand::execute() const {
		model::Room *room = mPlayer.room();

		render(*room);
	}

	void game::MapCommand::render(model::Room &room) const {

		// create buffer
		int width = room.floor()->width() * mZoomFactor + 3;
		int height = room.floor()->height() * mZoomFactor + 3;

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

				model::Room &otherRoom = passage->otherSide(*currentRoom);

				if(otherRoom.isVisited() || mCheat)
					drawPassage(mGrid, passage);

				if(markedRooms.count(&otherRoom) == 0) {
					markedRooms[&otherRoom] = true;
					queue.push(&otherRoom);

					Point position = otherRoom.position();
					mGrid[(position.y() + 1) * mZoomFactor][(position.x() + 1) * mZoomFactor] = otherRoom.repr();
					i++;
				}
			}
		}

		mGrid[(room.position().y() + 1) * mZoomFactor][(room.position().x() + 1) * mZoomFactor] = '@';

		std::cout << "Drawn" << i << "Rooms" << std::endl;

		// render to screen
		for(int y = 0; y < height; ++y) {
			for(int x = 0; x < width; ++x) {
				char c = mGrid[y][x];
				if(c == '@')
					std::cout << csl::color(csl::LIGHTRED);
                else
                    std::cout << csl::color(csl::WHITE);
				std::cout << mGrid[y][x];
			}
			std::cout << std::endl;
		}

		// delete mGrid
        for(int i = 0; i < height; ++i) {
            delete[] mGrid[i];
        }
        delete[] mGrid;
	}

	void game::MapCommand::drawPassage(char **grid, model::Passage *passage) const {
		model::Room &aRoom = passage->sideA();
		Point aPosition = aRoom.position();

        int y = (aPosition.y() + 1) * mZoomFactor;
        int x = (aPosition.x() + 1) * mZoomFactor;
        char c = passage->isCollapsed() ? '~' : passage->isNorth() || passage->isSouth() ? '|' : '-';

        // draw passage
        if(passage->isNorth()) {
			y -= 1;
		} else if(passage->isSouth()) {
            y += 1;
		} else if(passage->isEast()) {
            x += 1;
		} else if(passage->isWest()) {
			x -= 1;
		}

        grid[y][x] = c;

        // draw weight
		if(mCheat) {
			std::string weight{std::to_string(passage->weight())};
			if(passage->isNorth() || passage->isSouth()) {
				for(char c : weight)
					grid[y++][x] = c;
			} else {
				for(char c : weight)
					grid[y][x++] = c;
			}
		}
	}

    game::MapCommand *game::MapCommand::create(Parameters parameters) {
        return new dc::game::MapCommand(ServiceLocator::getInstance().resolve<dc::model::Game>().player(), parameters.num() > 0 && parameters.param(0) == "cheat");
    }

	bool game::MapCommand::isAction() const {
		return false;
	}
}