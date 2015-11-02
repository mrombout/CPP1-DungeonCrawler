#include "generator/DungeonGenerator.h"
#include "loader/MobLoader.h"
#include "loader/InventoryLoader.h"
#include "loader/TrapLoader.h"
#include "loader/RoomDescriptionLoader.h"
#include "loader/ItemLoader.h"
#include "util/ServiceLocator.h"
#include "generator/MobGenerator.h"
#include "generator/RoomGenerator.h"
#include "generator/FloorGenerator.h"
#include "generator/SimpleFloorGenerator.h"
#include "generator/BSPFloorGenerator.h"
#include "generator/DungeonGenerator.h"
#include "state/WelcomeState.h"
#include "command/NewGameCommand.h"
#include "Options.h"
#include "GameLoop.h"
#include "spell/Flipendo.h"
#include "spell/Musagus.h"

int main(int argc, char *argv[])
{
    // create game
    dc::game::GameLoop gameLoop;

    // register services
    ServiceLocator &sl = ServiceLocator::getInstance();

    // add instances
    dc::game::MobGenerator mobGenerator = dc::game::MobGenerator();
    dc::game::RoomGenerator roomGenerator = dc::game::RoomGenerator(mobGenerator);
    dc::model::Options options;

    sl.addInstance<dc::game::GameLoop>(gameLoop);
    sl.addInstance<dc::game::MobGenerator>(mobGenerator);
    sl.addInstance<dc::game::RoomGenerator>(roomGenerator);
    sl.addInstance<dc::model::Options>(options);

    dc::game::MobLoader mobLoader;
    dc::game::InventoryLoader inventoryLoader;
    dc::game::TrapLoader trapLoader;
    dc::game::RoomDescriptionLoader roomDescriptionLoader;
    dc::game::ItemLoader itemLoader;

    sl.addInstance<dc::game::MobLoader>(mobLoader);
    sl.addInstance<dc::game::InventoryLoader>(inventoryLoader);
    sl.addInstance<dc::game::TrapLoader>(trapLoader);
    sl.addInstance<dc::game::RoomDescriptionLoader>(roomDescriptionLoader);
    sl.addInstance<dc::game::ItemLoader>(itemLoader);

    dc::model::Flipendo flipendo;
    dc::model::Musagus musagus;

    sl.addInstance<dc::model::Spell>("flipendo", flipendo);
    sl.addInstance<dc::model::Spell>("musagus", musagus);

    // add factories
    sl.addFactory<dc::game::NewGameCommand>([](ServiceLocator &sl) {
        return new dc::game::NewGameCommand(sl.resolve<dc::game::GameLoop>(), sl.resolve<dc::game::ItemLoader>());
    });
    sl.addFactory<dc::game::FloorGenerator>([](ServiceLocator &sl) -> dc::game::FloorGenerator* {
        dc::model::Options &options = sl.resolve<dc::model::Options>();
        dc::game::RoomGenerator &roomGenerator = sl.resolve<dc::game::RoomGenerator>();

        std::string generator = options.get("dungeon.type");
        if(generator == "dfs") {
            return new dc::game::SimpleFloorGenerator(roomGenerator);
        } else {
            return new dc::game::BSPFloorGenerator(roomGenerator);
        }
    });
    sl.addFactory<dc::game::DungeonGenerator>([](ServiceLocator &sl) {
        dc::game::FloorGenerator *floorGenerator = ServiceLocator::getInstance().create<dc::game::FloorGenerator>();
        dc::game::MobGenerator &mobGenerator = ServiceLocator::getInstance().resolve<dc::game::MobGenerator>();

        return new dc::game::DungeonGenerator(floorGenerator, mobGenerator);
    });

    // start game
    gameLoop.setState(new dc::game::WelcomeState());
	gameLoop.start();

    return 0;
}
