#include <iostream>
#include <stdlib.h>
#include "util/Random.h"
#include "util/console.h"
#include "Leaf.h"
#include "Point.h"

namespace dc {
    namespace game {
        int Leaf::MIN_LEAF_SIZE = 6;

        Leaf::Leaf(int x, int y, int width, int height) :
                mX(x),
                mY(y),
                mWidth(width),
                mHeight(height),
                mLeftChild(nullptr),
                mRightChild(nullptr),
                mRoom(nullptr) {

        }

        Leaf::~Leaf() {
            delete mLeftChild;
            delete mRightChild;
        }

        bool Leaf::split() {
            if(mLeftChild && mRightChild)
                return false; // already split

            bool splitH{rand() % 100 > 50};
            if(mWidth > mHeight && (float) mWidth / (float) mHeight >= 1.25)
                splitH = false;
            else if(mHeight > mWidth && (float) mHeight / (float) mWidth >= 1.25)
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
                mRightChild = new Leaf(mX + split, mY, mWidth - split, mHeight);
            }

            return true;
        }

        void Leaf::createRooms() {
            if(mLeftChild != nullptr || mRightChild != nullptr) {
                if(mLeftChild != nullptr) {
                    mLeftChild->createRooms();
                }
                if(mRightChild != nullptr) {
                    mRightChild->createRooms();
                }

                if(leftChild() != nullptr && rightChild() != nullptr) {
                    createHall(mLeftChild->room(), mRightChild->room());
                }
            } else {
                int roomWidth;
                int roomHeight;
                int roomX;
                int roomY;

                //Point roomSize(Random::nextInt(3, width() - 2), Random::nextInt(3, height() - 2));
                Point roomSize(Random::nextInt(3, width() - 2), Random::nextInt(3, height() - 2));
                Point roomPos(Random::nextInt(mX, mX + mWidth - roomSize.x()), Random::nextInt(mY, mY + mHeight - roomSize.y()));

                //mRoom = new Rectangle(mX + roomPos.x(), mY + roomPos.y(), roomSize.x(), roomSize.y());
                mRoom = new dc::game::Rectangle(roomPos.x(), roomPos.y(), roomSize.x(), roomSize.y());

                csl::log() << "create room(" << mRoom->left() << ", " << mRoom->top() << ", " << mRoom->right() <<", " << mRoom->bottom() << ")" << std::endl;
            }
        }

        void Leaf::createHall(dc::game::Rectangle *l, dc::game::Rectangle *r) {
            Point lPoint(l->center());
            Point rPoint(r->center());

            int xDiff = rPoint.x() - lPoint.x();
            int yDiff = rPoint.y() - lPoint.y();

            if(xDiff == 0 || yDiff == 0) {
                if(yDiff == 0) {
                    // just make a horizontal hallway
                    mHalls.push_back(new dc::game::Rectangle(lPoint.x(), lPoint.y(), xDiff, 1));
                } else {
                    // just make a vertical hallway
                    mHalls.push_back(new dc::game::Rectangle(lPoint.x(), lPoint.y(), 1, yDiff));
                }
            } else {
                // right-angled hallway
                if(rand() % 100 > 50) {
                    // horizontal first
                    if(xDiff > 0) {
                        // go right
                        mHalls.push_back(new dc::game::Rectangle(lPoint.x(), lPoint.y(), xDiff + 1, 1));
                        if(yDiff > 0) {
                            mHalls.push_back(new dc::game::Rectangle(lPoint.x() + xDiff, lPoint.y(), 1, abs(yDiff)));
                        } else {
                            mHalls.push_back(new dc::game::Rectangle(lPoint.x() + xDiff, lPoint.y() + yDiff, 1, abs(yDiff)));
                        }
                    } else {
                        // go left
                        mHalls.push_back(new dc::game::Rectangle(lPoint.x() + xDiff, lPoint.y(), xDiff, 1));
                        if(yDiff > 0) {
                            mHalls.push_back(new dc::game::Rectangle(lPoint.x() + xDiff, lPoint.y(), 1, abs(yDiff)));
                        } else {
                            mHalls.push_back(new dc::game::Rectangle(lPoint.x() + xDiff, lPoint.y() + yDiff, 1, abs(yDiff)));
                        }
                    }
                } else {
                    // vertical first
                    if(yDiff < 0) {
                        // go up
                        mHalls.push_back(new dc::game::Rectangle(lPoint.x(), lPoint.y() + yDiff, 1, abs(yDiff)));
                        if(xDiff > 0) {
                            mHalls.push_back(new dc::game::Rectangle(lPoint.x(), lPoint.y() + yDiff, xDiff, 1));
                        } else {
                            mHalls.push_back(new dc::game::Rectangle(lPoint.x() + xDiff, lPoint.y() + yDiff, abs(xDiff), 1));
                        }
                    } else {
                        // go down
                        mHalls.push_back(new dc::game::Rectangle(lPoint.x(), lPoint.y(), 1, yDiff));
                        if(xDiff > 0) {
                            mHalls.push_back(new dc::game::Rectangle(lPoint.x(), lPoint.y() + yDiff, xDiff, 1));
                        } else {
                            mHalls.push_back(new dc::game::Rectangle(lPoint.x() + xDiff, lPoint.y() + yDiff, abs(xDiff), 1));
                        }
                    }
                }
            }

            csl::log() << "Trying to connect (" << lPoint.x() << ", " << lPoint.y() << ") and (" << rPoint.x() << ", " << rPoint.y() << ")" << std::endl;
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

        dc::game::Rectangle *Leaf::room() const {
            if(mRoom != nullptr) {
                return mRoom;
            } else {
                dc::game::Rectangle *leftRoom = nullptr;
                dc::game::Rectangle *rightRoom = nullptr;
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
                else if(rand() % 100 > 50)
                    return leftRoom;
                else
                    return rightRoom;
            }
        }

        const std::vector<dc::game::Rectangle*> &Leaf::halls() const {
            return mHalls;
        }
    }
}
