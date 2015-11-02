#ifndef DUNGEONCRAWLER_SPELL_H
#define DUNGEONCRAWLER_SPELL_H

#include "Game.h"
#include "Character.h"

namespace dc {
    namespace model {
        class Spell {
        public:
            virtual void cast(dc::model::Character &character, dc::model::Game &game) const = 0;
        };
    }
}

#endif //DUNGEONCRAWLER_SPELL_H
