#ifndef DUNGEONCRAWLER_FLOORGENERATOR_H
#define DUNGEONCRAWLER_FLOORGENERATOR_H

#include <Floor.h>

class FloorGenerator {
public:
	virtual ~FloorGenerator();

private:
	virtual dc::model::Floor *generate(unsigned int seed, unsigned int level) = 0;
};


#endif //DUNGEONCRAWLER_FLOORGENERATOR_H
