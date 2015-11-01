#include "Options.h"
#include <string>

namespace dc {
    namespace model {
        Options::Options(){
			mMap.emplace("dungeon.width", "25");
			mMap.emplace("dungeon.height", "25");
			mMap.emplace("dungeon.type", "bsp");
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

        int Options::getInt(const std::string &name) {
            return std::stoi(mMap[name]);
        }
    }
}
