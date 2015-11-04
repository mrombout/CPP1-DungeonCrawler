#include <algorithm>
#include <vector>
#include "String.h"

std::string String::toLower(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    return input;
}

std::string String::toUpper(std::string input) {
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	return input;
}

std::vector<std::string> String::split(const std::string &text, char sep) {
	std::vector<std::string> tokens;
	int start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}

std::string String::trim(std::string &s) {
	while (s.compare(0, 1, " ") == 0)
		s.erase(s.begin()); // remove leading whitespaces
	while (s.size()>0 && s.compare(s.size() - 1, 1, " ") == 0)
		s.erase(s.end() - 1); // remove trailing whitespaces

	return s;
}
