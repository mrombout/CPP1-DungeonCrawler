#include "Character.h"
#include "Equipable.h"

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

        unsigned int Character::experience() const {
            return mExperience;
        }

        void Character::setExperience(unsigned int pExperience) {
            mExperience = pExperience;
        }

        void Character::increaseExperience(unsigned int pExperience) {
            mExperience += pExperience;
        }

        void Character::decreaseExperience(unsigned int pExperience) {
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
    }
}
