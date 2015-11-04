#ifndef DUNGEONCRAWLER_NOTIMPLEMENTEDEXCEPTION_H
#define DUNGEONCRAWLER_NOTIMPLEMENTEDEXCEPTION_H

#include <stdexcept>

namespace dc {
    namespace game {
        class NotImplementedException : public std::logic_error {
        public:
            NotImplementedException() :
                    std::logic_error("Test") {

            }
        };
    }
}

#endif //DUNGEONCRAWLER_NOTIMPLEMENTEDEXCEPTION_H
