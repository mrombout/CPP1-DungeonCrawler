#ifndef DUNGEONCRAWLER_NOTIMPLEMENTEDEXCEPTION_H
#define DUNGEONCRAWLER_NOTIMPLEMENTEDEXCEPTION_H

#include <stdexcept>

class NotImplementedException : public std::logic_error {
public:
    NotImplementedException() :
            std::logic_error("Test") {

    }
};

#endif //DUNGEONCRAWLER_NOTIMPLEMENTEDEXCEPTION_H
