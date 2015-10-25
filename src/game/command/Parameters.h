#ifndef DUNGEONCRAWLER_PARAMETERS_H
#define DUNGEONCRAWLER_PARAMETERS_H

#include <vector>
#include <string>

class Parameters {
public:
    Parameters(std::string input);

    const std::string &commandName() const;
    const std::vector<std::string> parameters() const;

    unsigned int num() const;
    const std::string &param(unsigned int paramNum) const;

private:
    std::string mCommandName;
    std::vector<std::string> mParameters;

    std::string mInput;
};

#endif //DUNGEONCRAWLER_PARAMETERS_H
