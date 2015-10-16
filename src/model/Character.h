#ifndef DUNGEONCRAWLER_CHARACTER_H
#define DUNGEONCRAWLER_CHARACTER_H

#include <string>

namespace dc {
    namespace model {
        class Equipable;
    }
}

namespace dc {
    namespace model {
        class Character {
        public:
            Character();

            const std::string &name() const;
            void setName(std::string pName);

            int health() const;
            void setHealth(int pHealth);
            void decreaseHealth(int pHealth);
            void increaseHealth(int pHealth);

            int level() const;
            void setLevel(int pLevel);
            void increaseLevel(int pLevel);
            void decreaseLevel(int pLevel);
            void levelUp();

            int experience() const;
            void setExperience(int pExperience);
            void increaseExperience(int pExperience);
            void decreaseExperience(int pExperience);

            int attack() const;
            void setAttack(int pAttack);

            int defence() const;
            void setDefence(int pDefence);

            int perception() const;
            void setPerception(int pPerception);

            Equipable &weapon() const;
            void setWeapon(Equipable *pWeapon);

        private:
            std::string mName;
            int mHealth;

            int mLevel;
            int mExperience;

            int mAttack;
            int mDefence;
            int mPerception;

            Equipable *mWeapon;
        };
    }
}


#endif //DUNGEONCRAWLER_CHARACTER_H
