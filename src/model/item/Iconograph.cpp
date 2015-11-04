#include <iostream>
#include "Iconograph.h"

void Iconograph::use(dc::model::Character &character) {
    std::cout << "You push the button and hear a faint rumbling sound followed by a tiny whistle. This thing must be broken." << std::endl;
}

dc::model::Item *Iconograph::clone() const {
    return new Iconograph(*this);
}
