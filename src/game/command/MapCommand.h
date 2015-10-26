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
			MapCommand(dc::model::Player &player);
			virtual void execute() const override;

            static MapCommand *create(Parameters parameters);

        private:
			dc::model::Player &mPlayer;

			void render(model::Room &room) const;
            void drawPassage(char **grid, model::Passage *passage) const;
        };
	}
}


#endif //DUNGEONCRAWLER_LOOKCOMMAND_H
