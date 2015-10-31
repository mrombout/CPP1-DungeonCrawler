#ifndef DUNGEONCRAWLER_POINT_H
#define DUNGEONCRAWLER_POINT_H

#include <ostream>
#include <istream>

class Point {
public:
    Point(int x, int y);

    int x() const;
    int y() const;

    void setX(int x);
    void setY(int y);

	void up();
	void down();
	void left();
	void right();

    friend std::ostream &operator<<(std::ostream &output, const Point &p);
    friend std::istream &operator>>(std::istream &input, Point &p);

private:
    int mX;
    int mY;
};

#endif //DUNGEONCRAWLER_POINT_H
