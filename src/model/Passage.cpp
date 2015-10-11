#include "Passage.h"

namespace dc {
    namespace model {

        Passage::Passage(Direction direction, Room &sideA, Room &sideB) :
            mSideA(sideA),
            mSideB(sideB),
			mDirection(direction) {

        }

	    Passage::Direction Passage::direction() const {
			return mDirection;
	    }

	    Room& Passage::sideA() const {
			return mSideA;
	    }

	    Room& Passage::sideB() const {
			return mSideB;
	    }
    }
}