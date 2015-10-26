#ifndef DUNGEONCRAWLER_FLOORGENERATOR_H
#define DUNGEONCRAWLER_FLOORGENERATOR_H

#include "Floor.h"

namespace dc {
	namespace game {
		class FloorGenerator {
		public:
			virtual ~FloorGenerator();

			virtual dc::model::Floor *generate(unsigned int level) = 0;
		};
	}
}

#endif //DUNGEONCRAWLER_FLOORGENERATOR_H
