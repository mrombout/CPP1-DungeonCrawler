#include <iostream>
#include <stdlib.h>
#include "AttackCommand.h"
#include "Equipable.h"
#include "Mob.h"

AttackCommand::AttackCommand(dc::model::Player &player) :
        mPlayer(player) {

}

void AttackCommand::execute() const {
    /*
    std::cout << "You attack the " << mMob.name() << " and, ";
    if(rand() % 100 > 50) {
        int damage = 1;
        std::cout << "hit.\nYou do " << damage << " damage!" << std::endl;

        mMob.damage(damage);
    } else {
        std::cout << "miss." << std::endl;
    }
    */
}
