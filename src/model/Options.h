#ifndef DUNGEONCRAWLER_OPTIONS_H
#define DUNGEONCRAWLER_OPTIONS_H

#include <map>

namespace dc {
    namespace model {
        class Options {
        public:
            Options();

            void set(std::string name, std::string value);
            std::string get(const std::string &name);
            const std::map<std::string, std::string> all() const;

        private:
            std::map<std::string, std::string> mMap;
        };
    }
}

#endif //DUNGEONCRAWLER_OPTIONS_H
