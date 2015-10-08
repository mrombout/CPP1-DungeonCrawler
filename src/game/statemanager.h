#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <string>
#include <vector>

namespace dc {
    namespace engine {
        class Game;
        class State;
        class Command;
    }
}

namespace dc {
namespace engine {

    class StateManager
    {
    public:
        StateManager(Game *owner) :
            mOwner(owner) { }
        virtual ~StateManager() { }

        State * currentState() const;

        void pushState(State *state);

        void setState(State *state);

        State * popState();

        std::string read();

        Command * eval(std::string input);

        void onPrint(Game &game, Command *command);

        bool isInState(const State *state) const;

    private:
        Game* mOwner;

        std::vector<State*> mStates;
    };

}
}

#endif // STATEMANAGER_H
