#include "game.h"
#include "statemanager.h"
#include "State/welcomestate.h"

int main(int argc, char *argv[])
{
    // create main
    dc::engine::Game game;
    game.setState(new dc::game::WelcomeState());
	game.start();

    return 0;
}
