#ifndef DUNGEONCRAWLER_POINT_H
#define DUNGEONCRAWLER_POINT_H

class Point {
public:
    Point(int x, int y);

    int x() const;
    int y() const;

    void setX(int x);
    void setY(int y);

private:
    int mX;
    int mY;
};

#endif //DUNGEONCRAWLER_POINT_H
