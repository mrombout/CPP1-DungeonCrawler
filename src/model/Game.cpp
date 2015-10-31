#include "Game.h"
#include "Dungeon.h"
#include "Player.h"

namespace dc {
    namespace model {
        Game::Game(unsigned int seed, dc::model::Dungeon *dungeon, dc::model::Player *player) :
            mSeed(seed),
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


        std::ostream &operator<<(std::ostream &output, const Game &c) {
            output << c.mSeed;

            return output;
        }
    }
}
