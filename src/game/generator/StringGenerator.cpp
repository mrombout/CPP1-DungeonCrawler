#include <stdlib.h>
#include "StringGenerator.h"

namespace dc {
    namespace game {
        std::vector<std::string> StringGenerator::generate(std::vector<std::vector<std::string>> &sources) {
            std::vector<std::string> result;

            for(std::vector<std::string> source : sources) {
                result.push_back(source[rand() % source.size()]);
            }

            return result;
        }

        std::string StringGenerator::generateString(std::vector<std::vector<std::string>> &sources) {
            std::vector<std::string> result = generate(sources);
            std::string stringResult = "";
            for(int i = 0; i < result.size(); i++) {
                stringResult.append(result[i]);
            }

            return stringResult;
        }

    }
}
