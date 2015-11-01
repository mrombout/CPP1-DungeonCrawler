#ifndef DUNGEONCRAWLER_MOB_H
#define DUNGEONCRAWLER_MOB_H

#include "Character.h"

namespace dc {
    namespace model {
        class Mob : public Character {
        public:
            Mob(unsigned int id);

            void kill();
            virtual void damage(unsigned int pDamage) override;

            void tick(dc::model::Character &character);

            friend std::ostream &operator<<(std::ostream &output, const Mob &m);
            friend std::istream &operator>>(std::istream &input, Mob &m);

        private:
            unsigned int mId;
        };
    }
}

#endif //DUNGEONCRAWLER_MOB_H
