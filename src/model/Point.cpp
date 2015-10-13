#include "Point.h"

Point::Point(int x, int y) :
    mX(x),
    mY(y) {

}

int Point::x() const {
    return mX;
}

int Point::y() const {
    return mY;
}

void Point::setX(int x) {
    mX = x;
}

void Point::setY(int y) {
    mY = y;
}

void Point::up() {
	--mY;
}

void Point::down() {
	++mY;
}

void Point::left() {
	--mX;
}

void Point::right() {
	++mX;
}