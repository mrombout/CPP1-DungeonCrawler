#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>
#include "state.h"

namespace dc {
namespace engine {

    template <class T>
    class StateManager
    {
    public:
        StateManager(T *owner) :
            mOwner(owner) { }
        virtual ~StateManager() { }

        State<T> *currentState() const
        {
            if(mStates.empty())
                return 0;
            return mStates.back();
        }

        void pushState(State<T> *state)
        {
            if(currentState())
                currentState()->onLeave(mOwner);

            mStates.push_back(state);

            if(!currentState()->isInitilized()) {
                currentState()->onInitialize(mOwner);
            }

            if(currentState()) {
                currentState()->onEnter(mOwner);
            }
        }

        void setState(State<T> *state)
        {
            if(currentState()) {
                currentState()->onLeave(mOwner);
                mStates.pop_back();
            }

            mStates.push_back(state);

            if(!currentState()->isInitialized()) {
                currentState()->onInitialize(mOwner);
            }

            if(currentState()) {
                currentState()->onEnter(mOwner);
            }
        }

        State<T> *popState()
        {
            State<T> *state = mStates.back();

            if(currentState()) {
                currentState()->onLeave(mOwner);
                mStates.pop_back();
            }

            if(currentState()) {
                currentState()->onEnter();
            }

            return state;
        }

        std::string read() {
            if(currentState()) {
                return currentState()->onRead();
            }
            return 0;
        }
        Command *eval(std::string input) {
            if(currentState()) {
                return currentState()->onEval(input);
            }
            return 0;
        }
        void print(Command *command) {
            if(currentState()) {
                currentState()->onPrint(command);
            }
        }

        bool isInState(const State<T> *state) const
        {
            return state == currentState();
        }

    private:
        T* mOwner;

        std::vector<State<T>*> mStates;
    };

}
}

#endif // STATEMANAGER_H
