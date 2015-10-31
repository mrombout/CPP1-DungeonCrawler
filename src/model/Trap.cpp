#include <iomanip>
#include <iostream>
#include "Trap.h"

namespace dc {
    namespace model {
        Trap::Trap() :
                mDiscovered(false),
                mSprung(false),
                mDismantled(false) {

        }

        bool Trap::isDiscovered() {
            return mDiscovered;
        }

        void Trap::discover() {
            mDiscovered = true;
            bool willDismantle = (rand() % 100 > 50) ? true : false;

            if (willDismantle) {
                dismantle();
                std::cout << "You found a trap, and dismantled it before it struck" << std::endl;
            } else {
                std::cout << "You found a trap, but failed to dismantle it." << std::endl;
            }
        }

        bool Trap::isSprung() {
            return mSprung;
        }

        void Trap::spring(dc::model::Player &player) {
            if (!isDismantled()) {
                mSprung = true;

                onSpring(player);
            } else {
                std::cout << "Luckely you dismantled me, otherwise I would have sprung!" << std::endl;
            }
        }

        bool Trap::isDismantled() {
            return mDismantled;
        }

        void Trap::dismantle() {
            mDismantled = true;
        }

        std::ostream &operator<<(std::ostream &output, const Trap &t) {
            output << std::fixed << std::setprecision(15) << t.id() << "\t" << t.mDiscovered << "\t" << t.mDismantled << "\t" << t.mSprung;

            return output;
        }

        std::istream &operator>>(std::istream &input, Trap &t) {
            input >> t.mDiscovered >> t.mDismantled >> t.mSprung;

            return input;
        }

    }
}
