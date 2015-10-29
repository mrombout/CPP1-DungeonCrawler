#include "Options.h"

namespace dc {
    namespace model {
        Options::Options() :
            mMap{{"dungeon.width", "25"}, {"dungeon.height", "25"}} {

        }

        void Options::set(std::string name, std::string value) {
            mMap[name] = value;
        }

        std::string Options::get(const std::string &name) {
            return mMap[name];
        }

        const std::map<std::string, std::string> Options::all() const {
            return mMap;
        }
    }
}
