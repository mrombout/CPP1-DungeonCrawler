#ifndef DUNGEONCRAWLER_TALISMAN_H
#define DUNGEONCRAWLER_TALISMAN_H

#include "Item.h"

namespace dc {
    namespace model {
        class Talisman : public Item {
        public:
            Talisman();

            virtual void use() override;
        };
    }
}

#endif //DUNGEONCRAWLER_TALISMAN_H
