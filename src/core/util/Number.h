#ifndef DUNGEONCRAWLER_NUMBER_H
#define DUNGEONCRAWLER_NUMBER_H

#include <string>

class Number {
public:
    static long toLong(const std::string &str);
    static int toInt(const std::string &str);
};

#endif //DUNGEONCRAWLER_NUMBER_H
