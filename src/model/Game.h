#ifndef DUNGEONCRAWLER_GAME_H
#define DUNGEONCRAWLER_GAME_H

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
            Game(Dungeon *dungeon, Player *player);
            ~Game();

            Player &player() const;
            Dungeon &dungeon() const;

        private:
            Dungeon *mDungeon;
            Player *mPlayer;
        };
    }
}


#endif //DUNGEONCRAWLER_GAME_H
