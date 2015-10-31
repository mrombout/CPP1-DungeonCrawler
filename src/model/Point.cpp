#include <iomanip>
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

std::ostream &operator<<(std::ostream &output, const Point &p) {
    output << std::fixed << std::setprecision(15) << p.mX << "\t" << p.mY;

    return output;
}

std::istream &operator>>(std::istream &input, Point &p) {
    input >> p.mX >> p.mY;

    return input;
}