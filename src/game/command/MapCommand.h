#ifndef DUNGEONCRAWLER_MAPCOMMAND_H
#define DUNGEONCRAWLER_MAPCOMMAND_H

#include "CommandParameters.h"
#include "command.h"

namespace dc {
	namespace game {
		class MapCommand : public engine::Command {
		public:
			virtual void execute(engine::CommandParameters &parameters) const override;

		private:
			void render(model::Room &room) const;

            void drawPassage(char **grid, model::Passage *passage) const;
        };
	}
}


#endif //DUNGEONCRAWLER_LOOKCOMMAND_H
