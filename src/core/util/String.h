#ifndef DUNGEONCRAWLER_STRING_H
#define DUNGEONCRAWLER_STRING_H

#include <string>
#include <vector>

class String {
public:
    static std::string toLower(std::string input);
	static std::string toUpper(std::string input);

	static std::vector<std::string> split(const std::string &text, char sep);
	static std::string trim(std::string &s);
};

#endif //DUNGEONCRAWLER_STRING_H
