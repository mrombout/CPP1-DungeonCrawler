#include "GameLoop.h"
#include "state/WelcomeState.h"
#include "util/ServiceLocator.h"
#include "command/NewGameCommand.h"
#include "generator/MobGenerator.h"
#include "generator/RoomGenerator.h"

int main(int argc, char *argv[])
{
    // create game
    dc::engine::GameLoop gameLoop;

    // register services
    ServiceLocator &sl = ServiceLocator::getInstance();

    MobGenerator mobGenerator = MobGenerator();
    RoomGenerator roomGenerator = RoomGenerator(mobGenerator);

    // add instances
    sl.addInstance<dc::engine::GameLoop>(gameLoop);
    sl.addInstance<MobGenerator>(mobGenerator);
    sl.addInstance<RoomGenerator>(roomGenerator);

    // add factories
    sl.addFactory<dc::game::NewGameCommand>([](ServiceLocator &sl) {
        return new dc::game::NewGameCommand(sl.resolve<dc::engine::GameLoop>());
    });

    // start game
    gameLoop.setState(new dc::game::WelcomeState());
	gameLoop.start();

    return 0;
}
