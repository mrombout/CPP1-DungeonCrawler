#include <stdlib.h>
#include "util/Random.h"
#include "MobGenerator.h"
#include "RoomGenerator.h"
#include "StringGenerator.h"
#include "BearTrap.h"
#include "MobCallTrap.h"
#include "NearDeathTrap.h"
#include "RatTrap.h"
#include "TeleportTrap.h"

namespace dc {
    namespace game {
        RoomGenerator::RoomGenerator(MobGenerator &mobGenerator) :
                mMobGenerator(mobGenerator) {

        }

        dc::model::Room *RoomGenerator::generate(unsigned int level) {
            int roomLevel = Random::nextInt(level - VARIANCE, level + VARIANCE);

            // create room
            dc::model::Room *room = new dc::model::Room(Point(0, 0), "Some Room", FileLoader::getInstance()->getRoomDescriptionLoader().getRandomRoom());

            // populate room
            generateTraps(room, level);
            generateMobs(room, level);

            return room;
        }

        void RoomGenerator::generateTraps(dc::model::Room *room, unsigned int level) {
            // TODO Onderstaande regel weer verwijderen, nodig voor testen dismantle functionaliteit bij "inspect" command
            room->addTrap(new dc::model::RatTrap());
            if(rand() % 100 < 25 && false) {

				std::string trapType = FileLoader::getInstance()->getTrapLoader().getRandomTrap();
				if (trapType == "BEARTRAP"){
					room->addTrap(new dc::model::BearTrap());
				}
				else if (trapType == "MOBCALLTRAP") {
					room->addTrap(new dc::model::MobCallTrap());
				}
				else if (trapType == "NEARDEATHTRAP"){
					room->addTrap(new dc::model::NearDeathTrap());
				}
				else if (trapType == "RATTRAP"){
					room->addTrap(new dc::model::RatTrap());
				}
				else if (trapType == "TELEPORTTRAP"){
					room->addTrap(new dc::model::TeleportTrap());
				}
				else {
					std::cout << "Sorry, we can't recognize the " + trapType + "." << std::endl;
				}
			
            }
        }

        void RoomGenerator::generateMobs(dc::model::Room *room, unsigned int level) {
            if(rand() % 100 < 40) {
                int numEnemies = Random::nextInt(1, 4);
                for(int i = 0; i < numEnemies; ++i) {
                    dc::model::Mob *mob = mMobGenerator.generate(level);
                    //room->addMob(mob);
                }
            }
        }
    }
}
