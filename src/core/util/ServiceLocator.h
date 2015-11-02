#ifndef DUNGEONCRAWLER_SERVICELOCATOR_H
#define DUNGEONCRAWLER_SERVICELOCATOR_H

#include <functional>
#include <typeinfo>
#include <vector>
#include <map>
#include <string>
#include "exception/NoSuchServiceException.h"

class ServiceLocator {
public:
    static ServiceLocator& getInstance() {
        static ServiceLocator instance;
        return instance;
    }

    template<class T> void removeInstance(const T &object) {
        removeInstance<T>("default", object);
    }

    template<class T> void removeInstance(const std::string &name, const T &object) {
        typeInstanceMap[typeid(T).name()].erase(name);
        if(typeInstanceMap[typeid(T).name()].empty()) {
            typeInstanceMap.erase(typeid(T).name());
        }
    }

    template<class T> void addInstance(const T &object) {
        addInstance<T>("default", object);
    }

    template<class T> void addInstance(const std::string &name, const T &object) {
        typeInstanceMap[typeid(T).name()][name] = (void*) &object;
    }

    template<class T> T& resolve() {
        return resolve<T>("default");
    }

    template<class T> T& resolve(const std::string &name) {
        T* s = (T*)typeInstanceMap[typeid(T).name()][name];
        if(!s)
            throw NoSuchServiceException(name);
        return *(s);
    }

    template<class T> void addFactory(std::function<T*(ServiceLocator&)> factory) {
        factoryMap[typeid(T).name()] = factory;
    }

    template<class T> T* create() {
        std::function<void*(ServiceLocator&)> &factoryFunction = factoryMap[typeid(T).name()];
        void* factoryResult = factoryFunction(*this);

        return (T*)factoryResult;
    }

private:
    ServiceLocator() { };
    ServiceLocator(ServiceLocator const&) = delete;
    void operator=(ServiceLocator const&) = delete;

    std::map<std::string, std::map<std::string, void*>> typeInstanceMap;
    std::map<std::string, std::function<void*(ServiceLocator&)>> factoryMap;
};

#endif //DUNGEONCRAWLER_SERVICELOCATOR_H
