#ifndef DUNGEONCRAWLER_CHARACTER_H
#define DUNGEONCRAWLER_CHARACTER_H

#include "Equipable.h"

namespace dc {
    namespace model {
        class Character {
        private:
            int mName;
            int mHealth;

            int mLevel;
            int mExperience;

            int mAttack;
            int mDefence;
            int mPerception;

            Equipable &mWeapon;
        };
    }
}


#endif //DUNGEONCRAWLER_CHARACTER_H
