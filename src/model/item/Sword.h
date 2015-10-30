#ifndef DUNGEONCRAWLER_SWORD_H
#define DUNGEONCRAWLER_SWORD_H

#include <string>
#include "Equipable.h"

namespace dc {
    namespace model {
        class Sword : public Equipable {

        public:
            Sword(std::string name, std::string description, int damage);
            virtual ~Sword();

            virtual Item *clone() const;
        };
    }
}

#endif //DUNGEONCRAWLER_SWORD_H
