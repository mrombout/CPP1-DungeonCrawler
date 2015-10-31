#include "Equipable.h"

dc::model::Equipable::Equipable(unsigned int id, std::string name, std::string description, int damage) :
    mDamage(damage),
    Item(id, name, description) {

}

dc::model::Equipable::~Equipable() {

}


int dc::model::Equipable::damage() const {
    return mDamage;
}

void dc::model::Equipable::setDamage(int damage) {
    mDamage = damage;
}
