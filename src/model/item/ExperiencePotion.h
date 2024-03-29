#ifndef DUNGEONCRAWLER_EXPERIENCEPOTION_H
#define DUNGEONCRAWLER_EXPERIENCEPOTION_H

#include "Potion.h"

namespace dc {
    namespace model {
        class ExperiencePotion : public Potion {
        public:
            ExperiencePotion(unsigned int id, const std::string &name, const std::string &description, int effect);

            virtual void consume(Character &character) override;

            virtual Item *clone() const;
        };
    }
}

#endif //DUNGEONCRAWLER_EXPERIENCEPOTION_H
