#ifndef DUNGEONCRAWLER_EQUIPABLE_H
#define DUNGEONCRAWLER_EQUIPABLE_H

#include "item/Item.h"

namespace dc {
    namespace model {
        class Equipable : public Item {
        public:
            Equipable(unsigned int id, std::string name, std::string description, int damage);
            virtual ~Equipable();

            int damage() const;
            void setDamage(int damage);

        private:
            int mDamage;
        };
    }
}

#endif //DUNGEONCRAWLER_EQUIPABLE_H
