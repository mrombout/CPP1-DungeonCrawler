#ifndef DUNGEONCRAWLER_GAME_H
#define DUNGEONCRAWLER_GAME_H

#include <iostream>

namespace dc {
    namespace model {
        class Dungeon;
        class Player;
    }
}

namespace dc {
    namespace model {
        class Game {
        public:
            Game(unsigned int seed, Dungeon *dungeon, Player *player);
            ~Game();

            Player &player() const;
            Dungeon &dungeon() const;

            friend std::ostream &operator<<(std::ostream &output, const Game &g);

        private:
            unsigned int mSeed;

            Dungeon *mDungeon;
            Player *mPlayer;
        };
    }
}


#endif //DUNGEONCRAWLER_GAME_H
