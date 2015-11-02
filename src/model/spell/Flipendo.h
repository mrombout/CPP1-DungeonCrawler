#ifndef DUNGEONCRAWLER_FLIPENDO_H
#define DUNGEONCRAWLER_FLIPENDO_H

#include "Spell.h"

namespace dc {
    namespace model {
        class Flipendo : public Spell {

            virtual void cast(dc::model::Character &character, dc::model::Game &game) const;
        };
    }
}

#endif //DUNGEONCRAWLER_FLIPENDO_H
