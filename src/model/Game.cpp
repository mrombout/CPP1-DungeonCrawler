#include "Game.h"
#include "Dungeon.h"
#include "Player.h"

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

        Player &Game::player() const {
            return *mPlayer;
        }

        Dungeon &Game::dungeon() const {
            return *mDungeon;
        }
    }
}
