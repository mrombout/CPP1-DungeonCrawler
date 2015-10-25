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
    void createHall(dc::Rectangle *l, dc::Rectangle *r);

    int x() const;
    int y() const;
    int width() const;
    int height() const;

    Leaf *leftChild() const;
    Leaf *rightChild() const;

    dc::Rectangle *room() const;
    const std::vector<dc::Rectangle*> &halls() const;

private:
    int mX;
    int mY;
    int mWidth;
    int mHeight;

    Leaf *mLeftChild;
    Leaf *mRightChild;

    dc::Rectangle *mRoom;
    std::vector<dc::Rectangle*> mHalls;
    // TODO: Halls
};

#endif //DUNGEONCRAWLER_LEAF_H
