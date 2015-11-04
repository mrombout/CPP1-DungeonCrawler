#ifndef DUNGEONCRAWLER_POTION_H
#define DUNGEONCRAWLER_POTION_H

#include <functional>
#include "Consumable.h"

namespace dc {
    namespace model {
        class Potion : public Consumable {
        public:
            Potion(unsigned int, std::string name, std::string description, int effect);

        protected:
            int effect() const;

        private:
            int mEffect;
        };
    }
}

#endif //DUNGEONCRAWLER_POTION_H
