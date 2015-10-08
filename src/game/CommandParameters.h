#ifndef DUNGEONCRAWLER_COMMANDPARAMETERS_H
#define DUNGEONCRAWLER_COMMANDPARAMETERS_H

#include "Player.h"

namespace dc {
    namespace engine {
        class State;
        class GameLoop;
    }
}

namespace dc {
    namespace engine {
        class CommandParameters {
        public:
            CommandParameters(GameLoop &game, model::Player &player, State &state) :
                    mGame(game),
                    mPlayer(player),
                    mState(state) {

            }

            GameLoop &game() const {
                return mGame;
            }

            model::Player &player() const {
                return mPlayer;
            }

            State &state() const {
                return mState;
            }

        private:
            GameLoop &mGame;
            model::Player &mPlayer;
            State &mState;
        };
    }
}

#endif //DUNGEONCRAWLER_COMMANDPARAMETERS_H
