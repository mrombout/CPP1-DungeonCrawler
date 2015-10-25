#ifndef DUNGEONCRAWLER_SERVICELOCATOR_H
#define DUNGEONCRAWLER_SERVICELOCATOR_H

#include <typeinfo>
#include <map>
#include <string>

class ServiceLocator {
public:
    template<class T> static void add(const T& object) {
        add<T>("default", object);
    }

    template<class T> static void add(const std::string &name, const T& object) {
        typeInstanceMap[typeid(T).name()][name] = (void*) &object;
    }

    template<class T> static T& resolve() {
        return resolve<T>("default");
    }

    template<class T> static T& resolve(const std::string &name) {
        return *((T*)typeInstanceMap[typeid(T).name()][name]);
    }

    static std::map<std::string, std::map<std::string, void*>> typeInstanceMap;
};

#endif //DUNGEONCRAWLER_SERVICELOCATOR_H
