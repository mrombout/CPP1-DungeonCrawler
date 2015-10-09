#ifndef DUNGEONCRAWLER_FLOORGENERATOR_H
#define DUNGEONCRAWLER_FLOORGENERATOR_H

#include <Floor.h>

class FloorGenerator {
    virtual dc::model::Floor *generate(unsigned int seed, int level) = 0;
};


#endif //DUNGEONCRAWLER_FLOORGENERATOR_H
