#ifndef DUNGEONCRAWLER_ICONOGRAPH_H
#define DUNGEONCRAWLER_ICONOGRAPH_H

#include "Item.h"

/**
 * An iconograph is a wonderful device that allows you to make "instantaneous paintings".
 */
class Iconograph : public dc::model::Item {
public:
    Iconograph() : Item(-1, "Iconograph", "An iconograph is a wonderful device that allows you to make \"instantaneous paintings\".") { }

    virtual void use(dc::model::Character &character) override;
    virtual dc::model::Item *clone() const;
};


#endif //DUNGEONCRAWLER_ICONOGRAPH_H
