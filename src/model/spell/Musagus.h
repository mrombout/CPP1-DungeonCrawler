#ifndef DUNGEONCRAWLER_MUSAGUS_H
#define DUNGEONCRAWLER_MUSAGUS_H

#include "Spell.h"

namespace dc {
    namespace model {
        class Musagus : public Spell {
        public:

            virtual int cost() const;

            virtual void cast(dc::model::Character &character, dc::model::Game &game) const;
        };
    }
}

#endif //DUNGEONCRAWLER_MUSAGUS_H
