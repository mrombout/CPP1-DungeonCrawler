#ifndef DUNGEONCRAWLER_FIXTURE_H
#define DUNGEONCRAWLER_FIXTURE_H

#include "item/Item.h"

namespace dc {
    namespace model {
        class Fixture : public Item {
        public:
            Fixture(unsigned int id, const std::string &name, const std::string &description) : Item(id, name, description) { }


            virtual void pickUp(Player &player) override;
        };
    }
}

#endif //DUNGEONCRAWLER_FIXTURE_H
