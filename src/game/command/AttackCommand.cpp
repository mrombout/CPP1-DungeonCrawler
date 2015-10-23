#include <iostream>
#include "AttackCommand.h"
#include "Equipable.h"
#include "Mob.h"

AttackCommand::AttackCommand(dc::model::Mob &mob) :
    mMob(mob) {

}

void AttackCommand::execute(dc::engine::CommandParameters &parameters) const {
    std::cout << "You attack the " << mMob.name() << " and, ";
    if(rand() % 100 > 50) {
        int damage = 1;
        std::cout << "hit.\nYou do " << damage << " damage!" << std::endl;

        mMob.damage(damage);
    } else {
        std::cout << "miss." << std::endl;
    }
}
