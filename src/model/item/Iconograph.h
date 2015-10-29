#ifndef DUNGEONCRAWLER_ICONOGRAPH_H
#define DUNGEONCRAWLER_ICONOGRAPH_H

#include "Item.h"

/**
 * An iconograph is a wonderful device that allows you to make "instantaneous paintings".
 */
class Iconograph : public dc::model::Item {
public:
    Iconograph() : Item("Iconograph", "An iconograph is a wonderful device that allows you to make \"instantaneous paintings\".") { }

    virtual void use(dc::model::Character &character) override;
};


#endif //DUNGEONCRAWLER_ICONOGRAPH_H
