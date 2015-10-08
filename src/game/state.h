#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include "exception/NotImplementedException.h"
#include "command.h"
#include "game.h"

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

    virtual void onInitialize(Game* game) {

    }

    virtual void onEnter(Game* game) {

    }

    virtual void onLeave(Game* game) {

    }

    virtual std::string onRead() {
        std::string input;
        std::cin >> input;
        return input;
    }

    virtual Command* onEval(std::string input) {
        return 0;
    }

    virtual void onPrint(Game &game, Command *command) {
        try {
            command->execute();
        } catch(NotImplementedException e) {
            // TODO: Memleak, weghalen dit en even de player uit game halen oid
            model::Player *player = new model::Player();
            CommandParameters cp(game, *player, *this);
            command->execute(cp);
        }

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
