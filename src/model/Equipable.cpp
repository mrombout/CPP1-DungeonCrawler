#include "Equipable.h"

dc::model::Equipable::Equipable(std::string name, std::string description, int damage) :
    Item(name, description, damage) {

}

dc::model::Equipable::~Equipable() {

}
