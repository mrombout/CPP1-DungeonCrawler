#include <list>
#include <Game.h>
#include "util/ServiceLocator.h"
#include "util/console.h"
#include "util/DijkstraPathfinder.h"
#include "CheatMob.h"
#include "Room.h"
#include "Character.h"
#include "Player.h"
#include "Floor.h"

namespace dc {
    namespace game {
        CheatMob::CheatMob(dc::model::Player &player, dc::game::MobGenerator &mobGenerator) :
            mPlayer(player),
            mMobGenerator(mobGenerator) {

        }

        void CheatMob::execute() const {
            dc::model::Mob* superMob = mMobGenerator.generate(100);
            mPlayer.room()->addMob(superMob);
        }

        bool CheatMob::isAction() const {
            return false;
        }

        CheatMob *CheatMob::create(Parameters parameters) {
            ServiceLocator &sl = ServiceLocator::getInstance();

            return new CheatMob(sl.resolve<dc::model::Game>().player(), sl.resolve<dc::game::MobGenerator>());
        }
    }
}
