#include "Rectangle.h"

namespace dc {
    namespace game {
        Rectangle::Rectangle(int x, int y, int width, int height) :
                mX(x),
                mY(y),
                mWidth(width),
                mHeight(height) {

        }

        int Rectangle::left() const {
            return mX;
        }

        int Rectangle::top() const {
            return mY;
        }

        int Rectangle::right() const {
            return mX + mWidth;
        }

        int Rectangle::bottom() const {
            return mY + mHeight;
        }

        Point Rectangle::center() const {
            return Point(mX + mWidth / 2, mY + mHeight / 2);
        }
    }
}