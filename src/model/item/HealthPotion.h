#ifndef DUNGEONCRAWLER_HEALTHPOTION_H
#define DUNGEONCRAWLER_HEALTHPOTION_H

#include "Potion.h"

namespace dc {
    namespace model {
        class HealthPotion : public Potion {
        public:
            HealthPotion(unsigned int id, const std::string &name, const std::string &description, int effect);

            virtual void consume(Character &character) override;
            virtual Item *clone() const;
        };
    }
}

#endif //DUNGEONCRAWLER_HEALTHPOTION_H
