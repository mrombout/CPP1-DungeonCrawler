#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include "command.h"

namespace dc {
namespace engine {

template <class T>
class State
{
public:
    State() :
        mIsInitialized(false) {

    }

    virtual ~State() {

    }

    virtual void onInitialize(T* game) {

    }

    virtual void onEnter(T* game) {

    }

    virtual void onLeave(T* game) {

    }

    virtual std::string onRead() {
        std::string input;
        std::cin >> input;
        return input;
    }

    virtual Command* onEval(std::string input) {
        return 0;
    }

    virtual void onPrint(Command *command) {

    }

    bool isInitialized() const {
        return mIsInitialized;
    }

private:
    bool mIsInitialized;
};

}
}

#endif // STATE_H
