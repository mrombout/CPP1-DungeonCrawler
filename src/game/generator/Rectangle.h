#ifndef DUNGEONCRAWLER_RECTANGLE_H
#define DUNGEONCRAWLER_RECTANGLE_H

#include "Point.h"

namespace dc {
    namespace game {
        class Rectangle {
        public:
            Rectangle(int x, int y, int width, int height);

            Point center() const;

            int left() const;
            int top() const;

            int right() const;
            int bottom() const;

            int width() const;
            int height() const;

        private:
            int mX;
            int mY;
            int mWidth;
            int mHeight;
        };
    }
}

#endif //DUNGEONCRAWLER_RECTANGLE_H
