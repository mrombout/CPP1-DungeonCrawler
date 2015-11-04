#ifndef DUNGEONCRAWLER_MAPCOMMAND_H
#define DUNGEONCRAWLER_MAPCOMMAND_H

#include "command.h"

namespace dc {
    namespace model {
        class Player;
        class Room;
        class Passage;
    }
}

namespace dc {
	namespace game {
		class MapCommand : public game::Command {
		public:
			MapCommand(dc::model::Player &player, bool cheat);

			virtual void execute() const override;
            virtual bool isAction() const;

            static MapCommand *create(Parameters parameters);

        private:
            void render(model::Room &room) const;
            void drawPassage(char **grid, model::Passage *passage) const;

        private:
            const unsigned int mZoomFactor;
            bool mCheat;
			dc::model::Player &mPlayer;
        };
	}
}


#endif //DUNGEONCRAWLER_LOOKCOMMAND_H
