#include "Game.h"

namespace dc {
    namespace model {
        Game::Game(dc::model::Dungeon *dungeon, dc::model::Player *player) :
            mDungeon(dungeon),
            mPlayer(player) {

        }

        Game::~Game() {
            delete mDungeon;
            delete mPlayer;
        }
    }
}
