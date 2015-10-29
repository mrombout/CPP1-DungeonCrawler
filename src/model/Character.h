#ifndef DUNGEONCRAWLER_CHARACTER_H
#define DUNGEONCRAWLER_CHARACTER_H

#include <string>
#include "Inventory.h"

namespace dc {
    namespace model {
        class Equipable;
        class Room;
    }
}

namespace dc {
    namespace model {
        class Character {
        public:
            Character();
            Character(Room *room);

            const std::string &name() const;
            void setName(std::string pName);

            unsigned int maxHealth() const;
            void setMaxHealth(unsigned int pMaxHealth);

            bool isDead() const;

            int health() const;
            void setHealth(int pHealth);
            void decreaseHealth(int pHealth);
            void increaseHealth(int pHealth);
            virtual void damage(unsigned int pDamage);

            unsigned int level() const;
            void setLevel(unsigned int pLevel);
            void increaseLevel(unsigned int pLevel);
            void decreaseLevel(unsigned int pLevel);
            void levelUp();

            unsigned int experience() const;
            void setExperience(unsigned int pExperience);
            void increaseExperience(unsigned int pExperience);
            void decreaseExperience(unsigned int pExperience);

            unsigned int attack() const;
            void setAttack(unsigned int pAttack);

            unsigned int defence() const;
            void setDefence(unsigned int pDefence);

            unsigned int perception() const;
            void setPerception(unsigned int pPerception);

            Equipable &weapon() const;
            void setWeapon(Equipable *pWeapon);

            Room *room() const;

            virtual void setRoom(Room *room);

            Inventory &inventory() const;

        protected:
            std::string mName;

            unsigned int mMaxHealth;
            int mHealth;

            unsigned int mLevel;
            unsigned int mExperience;

            unsigned int mAttack;
            unsigned int mDefence;
            unsigned int mPerception;

            Equipable *mWeapon;

            Room *mRoom;

            Inventory *mInventory;
        };
    }
}


#endif //DUNGEONCRAWLER_CHARACTER_H
