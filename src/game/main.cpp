#include "GameLoop.h"
#include "statemanager.h"
#include "state/WelcomeState.h"

int main(int argc, char *argv[])
{
    // create main
    dc::engine::GameLoop game;
    game.setState(new dc::game::WelcomeState());
	game.start();

    return 0;
}
