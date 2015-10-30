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
    }
}