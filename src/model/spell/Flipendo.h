#ifndef DUNGEONCRAWLER_FLIPENDO_H
#define DUNGEONCRAWLER_FLIPENDO_H

#include "Spell.h"

namespace dc {
    namespace model {
        class Flipendo : public Spell {
        public:

            virtual int cost() const;

            virtual void cast(dc::model::Character &character, dc::model::Game &game) const;
        };
    }
}

#endif //DUNGEONCRAWLER_FLIPENDO_H
