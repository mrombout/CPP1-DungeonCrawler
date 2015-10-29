#ifndef DUNGEONCRAWLER_FLOORGENERATOR_H
#define DUNGEONCRAWLER_FLOORGENERATOR_H

#include "Floor.h"

namespace dc {
	namespace game {
		class FloorGenerator {
		public:
			virtual ~FloorGenerator();

			virtual model::Floor *generate(unsigned int level, unsigned int width, unsigned int height) = 0;
		};
	}
}

#endif //DUNGEONCRAWLER_FLOORGENERATOR_H
