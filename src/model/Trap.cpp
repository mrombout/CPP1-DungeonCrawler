#include "Trap.h"

dc::model::Trap::Trap() :
    mDiscovered(false),
    mSprung(false) {

}

bool dc::model::Trap::isDiscovered() {
    return mDiscovered;
}

void dc::model::Trap::discover() {
    mDiscovered = true;
}

bool dc::model::Trap::isSprung() {
    return mSprung;
}

void dc::model::Trap::spring(dc::model::Player &player) {
    mSprung = true;

    onSpring(player);
}
