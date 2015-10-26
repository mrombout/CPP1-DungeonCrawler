#include <iostream>
#include "Fixture.h"
#include "util/console.h"

namespace dc {
    namespace model {
        void dc::model::Fixture::pickUp(dc::model::Player &player) {
            std::cout << "You can not pick up that " << csl::color(csl::BLUE) << name() << "." << std::endl;
        }
    }
}
