#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include "exception/NotImplementedException.h"
#include "command.h"
#include "GameLoop.h"
#include "Room.h"

namespace dc {
namespace engine {

class State
{
public:
    State() :
        mIsInitialized(false) {

    }

    virtual ~State() {

    }

    virtual void onInitialize(GameLoop * game) {

    }

    virtual void onEnter(GameLoop * game) {

    }

    virtual void onLeave(GameLoop * game) {

    }

    virtual std::string onRead() {
        std::string input;
        std::cin >> input;
        return input;
    }

    virtual Command* onEval(std::string input) {
        return 0;
    }

    virtual void onPrint(GameLoop &game, Command *command) {
        command->execute(game);
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
