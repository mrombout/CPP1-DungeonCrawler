#ifndef DUNGEONCRAWLER_STRINGGENERATOR_H
#define DUNGEONCRAWLER_STRINGGENERATOR_H

#include <vector>
#include <string>

namespace dc {
    namespace game {
        class StringGenerator {
        public:
            static std::vector<std::string> generate(std::vector<std::vector<std::string>> &sources);
            static std::string generateString(std::vector<std::vector<std::string>> &sources);
        };
    }
}


#endif //DUNGEONCRAWLER_STRINGGENERATOR_H
