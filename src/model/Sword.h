#ifndef DUNGEONCRAWLER_SWORD_H
#define DUNGEONCRAWLER_SWORD_H

#include <string>
#include "Equipable.h"

namespace dc {
    namespace model {
        class Sword : public Equipable {

        public:
            Sword(const std::string &name, const std::string &description) : Equipable(name, description) { }

            virtual ~Sword();
        };
    }
}

#endif //DUNGEONCRAWLER_SWORD_H
