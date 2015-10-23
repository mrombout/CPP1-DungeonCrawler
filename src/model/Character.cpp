#include "Character.h"
#include "Equipable.h"

dc::model::Character::Character() :
    mWeapon(0),
    mHealth(0),
    mLevel(0),
    mExperience(0),
    mAttack(0),
    mDefence(0),
    mPerception(0) {

}

int dc::model::Character::name() const {
    return mName;
}

void dc::model::Character::setName(int pName) {
    mName = pName;
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
