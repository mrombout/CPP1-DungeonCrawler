#ifndef DUNGEONCRAWLER_MAPCOMMAND_H
#define DUNGEONCRAWLER_MAPCOMMAND_H

#include "CommandParameters.h"
#include "command.h"

namespace dc {
	namespace game {
		class MapCommand : public engine::Command {
			virtual void execute(engine::CommandParameters &parameters) const override;
			void render(model::Room &room) const;
		};
	}
}


#endif //DUNGEONCRAWLER_LOOKCOMMAND_H
