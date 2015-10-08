#ifndef DUNGEONCRAWLER_COMMANDPARAMETERS_H
#define DUNGEONCRAWLER_COMMANDPARAMETERS_H

#include "Player.h"

namespace dc {
    namespace engine {
        class State;
        class Game;
    }
}

namespace dc {
    namespace engine {
        class CommandParameters {
        public:
            CommandParameters(Game &game, model::Player &player, State &state) :
                    mGame(game),
                    mPlayer(player),
                    mState(state) {

            }

            Game &game() const {
                return mGame;
            }

            model::Player &player() const {
                return mPlayer;
            }

            State &state() const {
                return mState;
            }

        private:
            Game &mGame;
            model::Player &mPlayer;
            State &mState;
        };
    }
}

#endif //DUNGEONCRAWLER_COMMANDPARAMETERS_H
