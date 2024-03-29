#ifndef DUNGEONCRAWLER_CHARACTER_H
#define DUNGEONCRAWLER_CHARACTER_H

#include <string>
#include <iomanip>
#include <iostream>

namespace dc {
    namespace model {
        class Equipable;
        class Room;
        class Inventory;
    }
}

namespace dc {
    namespace model {
        class Character {
        public:
            Character();
            Character(Room *room);

            ~Character();

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

            unsigned int mana() const;
            void setMana(unsigned int pMana);
            void decreaseMana(unsigned int pMana);
            void increaseMana(unsigned int pMana);

            virtual unsigned int level() const;
            void setLevel(unsigned int pLevel);
            void increaseLevel(unsigned int pLevel);
            void decreaseLevel(unsigned int pLevel);
            void levelUp();

            double experience() const;
            void setExperience(double pExperience);
            void increaseExperience(double pExperience);
            void decreaseExperience(double pExperience);

            virtual unsigned int attack() const;
            void setAttack(unsigned int pAttack);

            unsigned int defence() const;
            void setDefence(unsigned int pDefence);

            virtual unsigned int perception() const;
            void setPerception(unsigned int pPerception);

            Equipable &weapon() const;
            void setWeapon(Equipable *pWeapon);

            Room *room() const;
            virtual void setRoom(Room *room);

            Inventory &inventory() const;

            friend std::ostream &operator<<(std::ostream &output, const Character &c);
            friend std::istream &operator>>(std::istream &input, Character &c);

        protected:
            std::string mName;

            unsigned int mMaxHealth;
            int mHealth;

            unsigned int mMana;

            unsigned int mLevel;
            double mExperience;

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
