#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <string>
#include <vector>

namespace dc {
    namespace engine {
        class GameLoop;
        class State;
        class Command;
    }
}

namespace dc {
namespace engine {

    class StateManager
    {
    public:
        StateManager(GameLoop *owner);
        virtual ~StateManager() { }

        State * currentState() const;

        void pushState(State *state);

        void setState(State *state);

        State * popState();

        std::string read();

        Command * eval(std::string input);

        void onPrint(GameLoop &game, Command *command);

        bool isInState(const State *state) const;

    private:
        GameLoop * mOwner;

        std::vector<State*> mStates;
    };

}
}

#endif // STATEMANAGER_H
