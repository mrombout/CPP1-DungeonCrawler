#include <algorithm>
#include "String.h"

std::string String::toLower(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    return input;
}
