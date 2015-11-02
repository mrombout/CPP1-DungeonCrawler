#ifndef DUNGEONCRAWLER_NOTANUMBEREXCEPTION_H
#define DUNGEONCRAWLER_NOTANUMBEREXCEPTION_H

#include <string>
#include <exception>

class NoSuchServiceException : public std::exception {
public:
    NoSuchServiceException(const std::string &serviceName);

    virtual const char *what() const throw() override;

private:
    std::string mServiceName;
    const char *mWhat;
};

#endif //DUNGEONCRAWLER_NOTANUMBEREXCEPTION_H
