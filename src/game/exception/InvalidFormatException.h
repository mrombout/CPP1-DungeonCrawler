#ifndef DUNGEONCRAWLER_NOTIMPLEMENTEDEXCEPTION_H
#define DUNGEONCRAWLER_NOTIMPLEMENTEDEXCEPTION_H

#include <stdexcept>

namespace dc {
    namespace game {
        class InvalidFormatException : public std::runtime_error {
        public:
            InvalidFormatException(const std::string &msg) :
                    std::runtime_error(msg) {

            }
        };
    }
}

#endif //DUNGEONCRAWLER_NOTIMPLEMENTEDEXCEPTION_H
