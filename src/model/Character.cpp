#include "Character.h"
#include "Equipable.h"

dc::model::Character::Character() :
    mMaxHealth(100),
    mHealth(mMaxHealth),
    mLevel(1),
    mExperience(0),
    mAttack(1),
    mDefence(1),
    mPerception(1),
    mWeapon(0) {

}

const std::string &dc::model::Character::name() const {
    return mName;
}

void dc::model::Character::setName(std::string pName) {
    mName = pName;
}

int dc::model::Character::maxHealth() const {
    return mMaxHealth;
}

void dc::model::Character::setMaxHealth(int pMaxHealth) {
    mMaxHealth = pMaxHealth;
}

int dc::model::Character::health() const {
    return mHealth;
}

void dc::model::Character::setHealth(int pHealth) {
    mHealth = pHealth;
}

void dc::model::Character::decreaseHealth(int pHealth) {
    mHealth -= pHealth;
}

void dc::model::Character::increaseHealth(int pHealth) {
    mHealth += pHealth;
}

int dc::model::Character::level() const {
    return mLevel;
}

void dc::model::Character::setLevel(int pLevel) {
    mLevel = pLevel;
}

void dc::model::Character::increaseLevel(int pLevel) {
    mLevel += pLevel;
}

void dc::model::Character::decreaseLevel(int pLevel) {
    mLevel -= pLevel;
}

void dc::model::Character::levelUp() {
    ++mLevel;
}

int dc::model::Character::experience() const {
    return mExperience;
}

void dc::model::Character::setExperience(int pExperience) {
    mExperience = pExperience;
}

void dc::model::Character::increaseExperience(int pExperience) {
    mExperience += pExperience;
}

void dc::model::Character::decreaseExperience(int pExperience) {
    mExperience -= pExperience;
}

int dc::model::Character::attack() const {
    return mAttack;
}

void dc::model::Character::setAttack(int pAttack) {
    mAttack = pAttack;
}

int dc::model::Character::defence() const {
    return mDefence;
}

void dc::model::Character::setDefence(int pDefence) {
    mDefence = pDefence;
}

int dc::model::Character::perception() const {
    return mPerception;
}

void dc::model::Character::setPerception(int pPerception) {
    mPerception = pPerception;
}

dc::model::Equipable &dc::model::Character::weapon() const {
    return *mWeapon;
}

void dc::model::Character::setWeapon(dc::model::Equipable *pWeapon) {
    mWeapon = pWeapon;
}

void dc::model::Character::damage(unsigned int pDamage) {
    decreaseHealth(pDamage);
}
