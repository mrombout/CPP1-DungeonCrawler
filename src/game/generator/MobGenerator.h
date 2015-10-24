#ifndef DUNGEONCRAWLER_MOBGENERATOR_H
#define DUNGEONCRAWLER_MOBGENERATOR_H

#include "Mob.h"

class MobGenerator {
public:
    static dc::model::Mob *generate(unsigned int level);
};

#endif //DUNGEONCRAWLER_MOBGENERATOR_H
