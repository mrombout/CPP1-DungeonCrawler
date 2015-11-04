#ifndef DUNGEONCRAWLER_COMPAS_H
#define DUNGEONCRAWLER_COMPAS_H

#include "item/Item.h"

namespace dc {
    namespace model {
        class Compass : public dc::model::Item {
        public:
            Compass();

            virtual void use(Character &character) override;

            virtual Item *clone() const;
        };
    }
}


#endif //DUNGEONCRAWLER_COMPAS_H
