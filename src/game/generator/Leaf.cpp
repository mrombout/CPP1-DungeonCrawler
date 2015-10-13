#include <stdlib.h>
#include "util/Random.h"
#include "Leaf.h"
#include "Point.h"

int Leaf::MIN_LEAF_SIZE = 0;

Leaf::Leaf(int x, int y, int width, int height) :
    mX(x),
    mY(y),
    mWidth(width),
    mHeight(height) {

}

Leaf::~Leaf() {
    delete mLeftChild;
    delete mRightChild;
}

bool Leaf::split(unsigned int seed) {
    srand(seed);

    if(mLeftChild && mRightChild)
        return false; // already split

    bool splitH{rand() > .5};
    if(mWidth > mHeight && mWidth / mHeight >= 1.25)
        splitH = false;
    else if(mHeight > mWidth && mHeight / mWidth >= 1.25)
        splitH = true;

    int max = (splitH ? mHeight : mWidth) - MIN_LEAF_SIZE;
    if(max <= MIN_LEAF_SIZE)
        return false; // too small

    int split = Random::nextInt(MIN_LEAF_SIZE, max);
    if(splitH) {
        mLeftChild = new Leaf(mX, mY, mWidth, split);
        mRightChild = new Leaf(mX, mY + split, mWidth, mHeight - split);
    } else {
        mLeftChild = new Leaf(mX, mY, split, mHeight);
        mRightChild = new Leaf(mY + split, mY, mWidth - split, mHeight - split);
    }

    return true;
}

void Leaf::createRooms(unsigned int seed) {
    if(mLeftChild != nullptr || mRightChild != nullptr) {
        if(mLeftChild != nullptr) {
            mLeftChild->createRooms(seed);
        }
        if(mRightChild != nullptr) {
            mRightChild->createRooms(seed);
        }

        if(leftChild() != nullptr && rightChild() != nullptr) {
            createHall(seed, mLeftChild->room(), mRightChild->room());
        }
    } else {
        int roomWidth;
        int roomHeight;
        int roomX;
        int roomY;

        roomWidth = Random::nextInt(3, width() - 2);
        roomHeight = Random::nextInt(3, height() - 2);

        roomX = Random::nextInt(1, width() - roomWidth - 1);
        roomY = Random::nextInt(1, height() - roomHeight - 1);

        mRoom = new Rectangle(mX + roomX, mY + roomY, roomWidth, roomHeight);
    }
}

void Leaf::createHall(unsigned int seed, Rectangle *l, Rectangle *r) {
    mHalls = new std::vector<Rectangle*>();

    Point *point1 = new Point(Random::nextInt(l->left() + 1, l->right() - 2), Random::nextInt(l->top() + 1, l->bottom() - 2));
    Point *point2 = new Point(Random::nextInt(r->left() + 1, r->right() - 2), Random::nextInt(r->top() + 1, r->bottom() - 2));

    int w = point2->x() - point1->x();
    int h = point2->y() - point1->y();

    if(w < 0) {
        if(h < 0) {
            if(rand() < .5) {
                mHalls->push_back(new Rectangle(point2->x(), point1->y(), abs(w), 1));
                mHalls->push_back(new Rectangle(point2->x(), point2->y(), 1, abs(h)));
            } else {
                mHalls->push_back(new Rectangle(point2->x(), point2->y(), abs(w), 1));
                mHalls->push_back(new Rectangle(point1->x(), point1->y(), 1, abs(h)));
            }
        } else if(h > 0) {
            if(rand() < .5) {
                mHalls->push_back(new Rectangle(point2->x(), point1->y(), abs(w), 1));
                mHalls->push_back(new Rectangle(point2->x(), point2->y(), 1, abs(h)));
            } else {
                mHalls->push_back(new Rectangle(point2->x(), point2->y(), abs(w), 1));
                mHalls->push_back(new Rectangle(point1->x(), point1->y(), 1, abs(h)));
            }
        } else if(h == 0) {
            mHalls->push_back(new Rectangle(point2->x(), point2->y(), abs(w), 1));
        }
    } else if(w > 0) {
        if(h < 0) {
            if(rand() < .5) {
                mHalls->push_back(new Rectangle(point1->x(), point2->y(), abs(w), 1));
                mHalls->push_back(new Rectangle(point1->x(), point2->y(), 1, abs(h)));
            } else {
                mHalls->push_back(new Rectangle(point1->x(), point1->y(), abs(w), 1));
                mHalls->push_back(new Rectangle(point2->x(), point2->y(), 1, abs(h)));
            }
        } else if(h > 0) {
            if(rand() < .5) {
                mHalls->push_back(new Rectangle(point1->x(), point1->y(), abs(w), 1));
                mHalls->push_back(new Rectangle(point2->x(), point1->y(), 1, abs(h)));
            } else {
                mHalls->push_back(new Rectangle(point1->x(), point2->y(), abs(w), 1));
                mHalls->push_back(new Rectangle(point2->x(), point1->y(), 1, abs(h)));
            }
        } else if(h == 1) {
            mHalls->push_back(new Rectangle(point1->x(), point1->y(), abs(w), 1));
        }
    } else {
        if(h < 0) {
            mHalls->push_back(new Rectangle(point2->x(), point2->y(), 1, abs(w)));
        } else if(h > 0) {
            mHalls->push_back(new Rectangle(point1->x(), point1->y(), 1, abs(h)));
        }
    }
}

int Leaf::x() const {
    return mX;
}

int Leaf::y() const {
    return mY;
}

int Leaf::width() const {
    return mWidth;
}

int Leaf::height() const {
    return mHeight;
}

Leaf *Leaf::leftChild() const {
    return mLeftChild;
}

Leaf *Leaf::rightChild() const {
    return mRightChild;
}

Rectangle *Leaf::room() const {
    if(mRoom != nullptr) {
        return mRoom;
    } else {
        Rectangle *leftRoom = nullptr;
        Rectangle *rightRoom = nullptr;
        if(mLeftChild != nullptr) {
            leftRoom = mLeftChild->room();
        }
        if(mRightChild != nullptr) {
            rightRoom = mRightChild->room();
        }
        if(leftRoom == nullptr && rightRoom == nullptr)
            return nullptr;
        else if(rightRoom == nullptr)
            return leftRoom;
        else if(leftRoom == nullptr)
            return rightRoom;
        else if(rand() > .5)
            return leftRoom;
        else
            return rightRoom;
    }
}
