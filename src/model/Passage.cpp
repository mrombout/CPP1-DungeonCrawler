#include "Passage.h"
#include "Room.h"

namespace dc {
    namespace model {
        Passage::Passage(Room &sideA, Room &sideB) :
            mSideA(sideA),
            mSideB(sideB),
            mCollapsed(false) {

        }

	    Room& Passage::sideA() const {
			return mSideA;
	    }

	    Room& Passage::sideB() const {
			return mSideB;
	    }

        Room &Passage::otherSide(const Room &room) const {
            return &mSideA == &room ? mSideB : mSideA;
        }

        int Passage::weight() const {
            return mSideA.weight() + mSideB.weight();
        }

        bool Passage::isCollapsed() const {
            return mCollapsed;
        }

        void Passage::setCollapsed(bool isCollapsed) {
            mCollapsed = isCollapsed;
        }

        bool Passage::isNorth() const {
            return mSideB.position().y() < mSideA.position().y();
        }

        bool Passage::isEast() const {
            return mSideB.position().x() > mSideA.position().x();
        }

        bool Passage::isSouth() const {
            return mSideB.position().y() > mSideA.position().y();
        }

        bool Passage::isWest() const {
            return mSideB.position().x() < mSideA.position().x();
        }
    }
}