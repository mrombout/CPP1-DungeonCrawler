#ifndef DUNGEONCRAWLER_ITEM_H
#define DUNGEONCRAWLER_ITEM_H

#include <string>
#include <Character.h>

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace model {
        class Item {
        public:
            Item(std::string name, std::string description);
            virtual ~Item() { }

            virtual void pickUp(Player &player);
            virtual void use(Character &character);

            bool partialMatch(const std::string &name) const;

            std::string name() const;
            std::string description() const;
        private:
            std::string mName;
            std::string mDescription;
            int mDamage;
        };
    }
}

#endif //DUNGEONCRAWLER_ITEM_H
