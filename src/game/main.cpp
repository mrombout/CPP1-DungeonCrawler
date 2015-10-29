#include "Options.h"
#include "GameLoop.h"
#include "state/WelcomeState.h"
#include "util/ServiceLocator.h"
#include "command/NewGameCommand.h"
#include "generator/MobGenerator.h"
#include "generator/RoomGenerator.h"

int main(int argc, char *argv[])
{
    // create game
    dc::game::GameLoop gameLoop;

    // register services
    ServiceLocator &sl = ServiceLocator::getInstance();

    dc::game::MobGenerator mobGenerator = dc::game::MobGenerator();
    dc::game::RoomGenerator roomGenerator = dc::game::RoomGenerator(mobGenerator);
    dc::model::Options options;

    // add instances
    sl.addInstance<dc::game::GameLoop>(gameLoop);
    sl.addInstance<dc::game::MobGenerator>(mobGenerator);
    sl.addInstance<dc::game::RoomGenerator>(roomGenerator);
    sl.addInstance<dc::model::Options>(options);

    // add factories
    sl.addFactory<dc::game::NewGameCommand>([](ServiceLocator &sl) {
        return new dc::game::NewGameCommand(sl.resolve<dc::game::GameLoop>());
    });

    // start game
    gameLoop.setState(new dc::game::WelcomeState());
	gameLoop.start();

    return 0;
}
