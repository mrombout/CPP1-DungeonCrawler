#include "Passage.h"

namespace dc {
    namespace model {

        Passage::Passage(Room &sideA, Room &sideB) :
            mSideA(sideA),
            mSideB(sideB) {

        }

	    Room& Passage::sideA() const {
			return mSideA;
	    }

	    Room& Passage::sideB() const {
			return mSideB;
	    }

        Room &Passage::otherSide(Room *room) {
            return &mSideA == room ? mSideB : mSideA;
        }
    }
}