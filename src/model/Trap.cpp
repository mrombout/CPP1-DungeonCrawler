#include <iostream>
#include "Trap.h"

dc::model::Trap::Trap() :
    mDiscovered(false),
    mSprung(false),
    mDismantled(false) {

}

bool dc::model::Trap::isDiscovered() {
    return mDiscovered;
}

void dc::model::Trap::discover() {
    mDiscovered = true;
    bool willDismantle = (rand() % 100 > 50) ? true : false;

    if (willDismantle) {
        dismantle();
        std::cout << "I found a trap, and dismantled it before it struck" << std::endl;
    }
}

bool dc::model::Trap::isSprung() {
    return mSprung;
}

void dc::model::Trap::spring(dc::model::Player &player) {
    if (!isDismantled()) {
        mSprung = true;

        onSpring(player);
    } else {
        std::cout << "Luckely you dismantled me, otherwise I would have sprung!" << std::endl;
    }
}

bool dc::model::Trap::isDismantled() {
    return mDismantled;
}

void dc::model::Trap::dismantle() {
    mDismantled = true;
}
