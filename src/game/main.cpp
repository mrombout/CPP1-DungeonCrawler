#include "GameLoop.h"
#include "statemanager.h"
#include "state/WelcomeState.h"
#include "util/ServiceLocator.h"
#include "command/NewGameCommand.h"
#include "generator/MobGenerator.h"
#include "generator/RoomGenerator.h"

int main(int argc, char *argv[])
{
    // create game
    dc::engine::GameLoop game;

    // register services
    ServiceLocator &sl = ServiceLocator::getInstance();

    MobGenerator mobGenerator = MobGenerator();
    RoomGenerator roomGenerator = RoomGenerator(mobGenerator);

    // add instances
    sl.addInstance<dc::engine::GameLoop>(game);
    sl.addInstance<MobGenerator>(mobGenerator);
    sl.addInstance<RoomGenerator>(roomGenerator);

    // add factories
    sl.addFactory<dc::game::NewGameCommand>([](ServiceLocator &sl) {
        return new dc::game::NewGameCommand();
    });

    // start game
    game.setState(new dc::game::WelcomeState());
	game.start();

    return 0;
}
