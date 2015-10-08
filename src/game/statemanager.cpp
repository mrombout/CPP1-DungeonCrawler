#include "statemanager.h"
#include "state.h"
#include "state/GameplayState.h"

namespace dc {
    namespace engine {
        StateManager::StateManager(GameLoop *owner) : mOwner(owner),
                                                      mStates() { }

        State *StateManager::currentState() const {
            if(mStates.empty())
                return 0;
            return mStates.back();
        }

        void StateManager::pushState(State *state) {
            if(currentState())
                currentState()->onLeave(mOwner);

            mStates.push_back(state);

            if(!currentState()->isInitialized()) {
                currentState()->onInitialize(mOwner);
            }

            if(currentState()) {
                currentState()->onEnter(mOwner);
            }
        }

        void StateManager::setState(State *state) {
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

        State *StateManager::popState() {
            State *state = mStates.back();

            if(currentState()) {
                currentState()->onLeave(mOwner);
                mStates.pop_back();
            }

            if(currentState()) {
                currentState()->onEnter(mOwner);
            }

            return state;
        }

        std::string StateManager::read() {
            if(currentState()) {
                return currentState()->onRead();
            }
            return 0;
        }

        Command *StateManager::eval(std::string input) {
            if(currentState()) {
                return currentState()->onEval(input);
            }
            return 0;
        }

        void StateManager::onPrint(GameLoop &game, Command *command) {
            if(currentState()) {
                if(game::GameplayState *state = dynamic_cast<game::GameplayState*>(currentState())) {
                    state->onPrint(game, command);
                } else {
                    currentState()->onPrint(game, command);
                }
            }
        }

        bool StateManager::isInState(const State *state) const {
            return state == currentState();
        }
    }
}