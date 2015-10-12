#ifndef DUNGEONCRAWLER_ITEM_H
#define DUNGEONCRAWLER_ITEM_H

#include <string>

namespace dc {
    namespace model {
        class Item {
        public:
            Item();
            virtual ~Item() = 0;

            std::string description() const;
        private:
            std::string mDescription;
        };
    }
}


#endif //DUNGEONCRAWLER_ITEM_H
