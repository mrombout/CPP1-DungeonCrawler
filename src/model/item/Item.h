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
            Item(unsigned int id, std::string name, std::string description);
            virtual ~Item() { }

            virtual Item* clone() const = 0;

            virtual void pickUp(Player &player);
            virtual void use(Character &character);

            virtual bool partialMatch(const std::string &name) const;

            unsigned int id() const;
            std::string name() const;
            std::string description() const;
        private:
            unsigned int mId;

            std::string mName;
            std::string mDescription;
        };
    }
}

#endif //DUNGEONCRAWLER_ITEM_H
