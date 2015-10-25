#ifndef DUNGEONCRAWLER_LEAF_H
#define DUNGEONCRAWLER_LEAF_H

#include <vector>
#include "Rectangle.h"

class Leaf {
public:
    static int MIN_LEAF_SIZE;

    Leaf(int x, int y, int width, int height);
    ~Leaf();

    bool split();
    void createRooms();
    void createHall(Rectangle *l, Rectangle *r);

    int x() const;
    int y() const;
    int width() const;
    int height() const;

    Leaf *leftChild() const;
    Leaf *rightChild() const;

    Rectangle *room() const;
    const std::vector<Rectangle*> &halls() const;

private:
    int mX;
    int mY;
    int mWidth;
    int mHeight;

    Leaf *mLeftChild;
    Leaf *mRightChild;

    Rectangle *mRoom;
    std::vector<Rectangle*> mHalls;
    // TODO: Halls
};

#endif //DUNGEONCRAWLER_LEAF_H
