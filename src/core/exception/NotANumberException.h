#ifndef DUNGEONCRAWLER_NOTANUMBEREXCEPTION_H
#define DUNGEONCRAWLER_NOTANUMBEREXCEPTION_H

#include <string>
#include <exception>

class NotANumberException : public std::exception {
public:
    NotANumberException(const std::string &num);

    virtual const char *what() const throw() override;

private:
    std::string mNum;
};

#endif //DUNGEONCRAWLER_NOTANUMBEREXCEPTION_H
