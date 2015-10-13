//
// Created by Robin de Mug on 10/12/15.
//

#ifndef DUNGEONCRAWLER_SWORD_H
#define DUNGEONCRAWLER_SWORD_H


#include "Item.h"

namespace dc {
    namespace model {
        class Sword : public Item {

        public:
            Sword(const std::string &description) : Item(description) { }
            ~Sword() { }
        };
    }
}


#endif //DUNGEONCRAWLER_SWORD_H
