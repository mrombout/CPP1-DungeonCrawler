#ifndef DUNGEONCRAWLER_PROP_H
#define DUNGEONCRAWLER_PROP_H

#include "item/Item.h"

namespace dc {
    namespace model {
        class Prop : public Item {
        public:
            Prop(unsigned int id, const std::string &name, const std::string &description) : Item(id, name, description) { }

            virtual void pickUp(Player &player) override;
            virtual void use(Character &character) override;
            virtual Item *clone() const;
        };
    }
}

#endif //DUNGEONCRAWLER_PROP_H
