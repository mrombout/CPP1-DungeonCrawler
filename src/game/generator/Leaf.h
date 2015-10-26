#ifndef DUNGEONCRAWLER_LEAF_H
#define DUNGEONCRAWLER_LEAF_H

#include <vector>
#include "Rectangle.h"

namespace dc {
    namespace game {
        class Leaf {
        public:
            static int MIN_LEAF_SIZE;

            Leaf(int x, int y, int width, int height);
            ~Leaf();

            bool split();
            void createRooms();
            void createHall(dc::game::Rectangle *l, dc::game::Rectangle *r);

            int x() const;
            int y() const;
            int width() const;
            int height() const;

            Leaf *leftChild() const;
            Leaf *rightChild() const;

            dc::game::Rectangle *room() const;
            const std::vector<dc::game::Rectangle*> &halls() const;

        private:
            int mX;
            int mY;
            int mWidth;
            int mHeight;

            Leaf *mLeftChild;
            Leaf *mRightChild;

            dc::game::Rectangle *mRoom;
            std::vector<dc::game::Rectangle*> mHalls;
            // TODO: Halls
        };
    }
}

#endif //DUNGEONCRAWLER_LEAF_H
