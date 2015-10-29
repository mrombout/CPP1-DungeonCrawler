#ifndef DUNGEONCRAWLER_HEALTHPOTION_H
#define DUNGEONCRAWLER_HEALTHPOTION_H

#include "Potion.h"

namespace dc {
    namespace model {
        class HealthPotion : public Potion {
        public:
            HealthPotion(const std::string &name, const std::string &description, int effect);


            virtual void consume(Character &character) override;
        };
    }
}

#endif //DUNGEONCRAWLER_HEALTHPOTION_H