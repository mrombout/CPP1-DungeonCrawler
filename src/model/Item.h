#ifndef DUNGEONCRAWLER_ITEM_H
#define DUNGEONCRAWLER_ITEM_H

#include <string>

namespace dc {
    namespace model {
        class Item {
        public:
            Item(std::string description);
            virtual ~Item();

            std::string description() const;
        private:
            std::string mDescription;
        };
    }
}


#endif //DUNGEONCRAWLER_ITEM_H
