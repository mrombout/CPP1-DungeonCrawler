#ifndef DUNGEONCRAWLER_STRINGGENERATOR_H
#define DUNGEONCRAWLER_STRINGGENERATOR_H

#include <vector>
#include <string>

class StringGenerator {
public:
    static std::vector<std::string> generate(std::vector<std::vector<std::string>> &sources, unsigned int seed);
};


#endif //DUNGEONCRAWLER_STRINGGENERATOR_H
