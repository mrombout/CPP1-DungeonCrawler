#include "Rectangle.h"

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
