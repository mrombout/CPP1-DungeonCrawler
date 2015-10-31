#include <math.h>
#include "Character.h"
#include "Inventory.h"
#include "item/Equipable.h"
#include "Room.h"
#include "Floor.h"

namespace dc {
    namespace model {
        Character::Character() :
                Character(nullptr) {

        }

        Character::Character(Room *room) :
                mMaxHealth(100),
                mHealth(mMaxHealth),
                mLevel(1),
                mExperience(0),
                mAttack(1),
                mDefence(1),
                mPerception(1),
                mWeapon(0),
                mRoom(room) {
            mInventory = new Inventory();
        }

        const std::string &Character::name() const {
            return mName;
        }

        void Character::setName(std::string pName) {
            mName = pName;
        }

        unsigned int Character::maxHealth() const {
            return mMaxHealth;
        }

        void Character::setMaxHealth(unsigned int pMaxHealth) {
            mMaxHealth = pMaxHealth;
        }

        int Character::health() const {
            return mHealth;
        }

        void Character::setHealth(int pHealth) {
            mHealth = pHealth;
        }

        void Character::decreaseHealth(int pHealth) {
            mHealth -= pHealth;
        }

        void Character::increaseHealth(int pHealth) {
            mHealth += pHealth;
        }

        unsigned int Character::level() const {
            return mLevel;
        }

        void Character::setLevel(unsigned int pLevel) {
            mLevel = pLevel;
        }

        void Character::increaseLevel(unsigned int pLevel) {
            mLevel += pLevel;
        }

        void Character::decreaseLevel(unsigned int pLevel) {
            mLevel -= pLevel;
        }

        void Character::levelUp() {
            ++mLevel;
        }

        double Character::experience() const {
            return mExperience;
        }

        void Character::setExperience(double pExperience) {
            mExperience = pExperience;
        }

        void Character::increaseExperience(double pExperience) {
            mExperience += pExperience;
        }

        void Character::decreaseExperience(double pExperience) {
            mExperience -= pExperience;
        }

        unsigned int Character::attack() const {
            return mAttack;
        }

        void Character::setAttack(unsigned int pAttack) {
            mAttack = pAttack;
        }

        unsigned int Character::defence() const {
            return mDefence;
        }

        void Character::setDefence(unsigned int pDefence) {
            mDefence = pDefence;
        }

        unsigned int Character::perception() const {
            return mPerception;
        }

        void Character::setPerception(unsigned int pPerception) {
            mPerception = pPerception;
        }

        Equipable &Character::weapon() const {
            return *mWeapon;
        }

        void Character::setWeapon(Equipable *pWeapon) {
            mWeapon = pWeapon;
        }

        void Character::damage(unsigned int pDamage) {
            decreaseHealth(pDamage);
        }

        Room *Character::room() const {
            return mRoom;
        }

        void Character::setRoom(Room *room) {
            mRoom = room;
        }

        Inventory &Character::inventory() const {
            return *mInventory;
        }

        bool Character::isDead() const {
            return mHealth <= 0;
        }

        std::ostream &operator<<(std::ostream &output, const Character &c) {
            output << std::fixed << std::setprecision(15) << c.mName << '\t' << c.mMaxHealth << "\t"
            << c.mHealth << "\t" << c.mLevel << "\t" << c.mExperience << "\t" << c.mAttack << "\t"
            << c.mDefence << "\t" << c.mPerception;

            output << "\t" << (c.mWeapon ? c.mWeapon->id() : 0);

            if (c.mRoom)
                output << "\t" << c.room()->position() << "\t" << c.room()->floor()->level();
            else
                output << "\t" << -1 << "\t" << -1 << "\t" << 0;

            return output;
        }

        std::istream &operator>>(std::istream &input, Character &c) {
            input >> c.mName >> c.mMaxHealth >> c.mHealth >> c.mLevel >> c.mExperience >> c.mAttack >> c.mDefence
                  >> c.mPerception;

            return input;
        }
    }
}
