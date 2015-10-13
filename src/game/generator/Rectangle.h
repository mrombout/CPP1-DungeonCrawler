#ifndef DUNGEONCRAWLER_RECTANGLE_H
#define DUNGEONCRAWLER_RECTANGLE_H

class Rectangle {
public:
    Rectangle(int x, int y, int width, int height);

    int left() const;
    int top() const;

    int right() const;
    int bottom() const;

private:
    int mX;
    int mY;
    int mWidth;
    int mHeight;
};

#endif //DUNGEONCRAWLER_RECTANGLE_H
