#include <stdlib.h>
#include <util/Random.h>
#include "MobGenerator.h"
#include "RoomGenerator.h"
#include "StringGenerator.h"
#include "BearTrap.h"
#include "EvilSummonTrap.h"
#include "NearDeathTrap.h"
#include "RatTrap.h"
#include "TeleportTrap.h"
#include "Mob.h"

std::vector<std::vector<std::string>> roomDescriptions{
    // room shape/size
    std::vector<std::string> {
        "You're in a large room, ",
        "You're in a small room, ",
        "You're in a long corridor, ",
        "You're in an oddly shaped room, ",
        "You're in a room, but you're not sure this room has any particular shape or form, ",
        "You're in a notably bland room in the shape of a sqaure, "
    },

    // room properties
    std::vector<std::string> {
        "its walls laid out of big gray stone, that once must have been even bigger rocks living their humble lives in the steppes plains. ",
        "the walls are of humble brick. ",
        "its prominently boring stone bricks are decorated with intriguing paintings. One of them appears to look like Barack Obama, a person coincidentally of no importance in the world of Rhovanar. ",
        "a cold breeze caresses your face lightly when you suddenly feel its icy cold fingers trace the back on your spine. You feel betrayed. ",
        "you feel a strong presence of magic in the air. It's probably nothing. ",
        "a foul stench enters your nostrils, partying with you turbinate and hitting on your oropharynx. It makes you slightly nauseous. ",
        "its really just that. ",
        "you feel a pleasant vibe in the air, but your feeling have betrayed you before. ",
        "for a moment you could've sworn you'd been here before. ",
        "the floor is made of a nice shaggy carpet. It feels nice even through the thick leather of your muddy boots. ",
        "the air in this room is damp and cold. "
    },

    std::vector<std::string> {
        "It has a dark feeling to it as it this was just the room for a sleezy teenager and his dog to go on a ghost investigation. ",
        "For a moment you see a bright flash of octarine, but you couldn't make out what colour it really was. ",
        "In the air you smell evilness. Some monsters must have been here before you. ",
        "And there isn't really more to it. With yet another boring room you reflect on your self if the quest you are on was the right choice after all. "
    },

    // furniture
    std::vector<std::string> {
        "In what would normally be called the corner there is a small little table. ",
        "It's awefully empty, it makes you wonder why this room is even here. ",
        "There's a huge treasure chest at the other end of the room. It would have been really awesome if it had more gold in it, and less rat droppings. ",
        "An unrealistic amount of hay is scathered all about the floor. ",
        "The room is full of torture equipment, all of them are awefully clean. It makes it even more eerie. ",
        "It's empty, as if this room came right of a room generator written by an author with lack of fantasy. ",
        "There's an aweful lot of nothingness stored in this room. ",
        "You feel as if this is the 2000th room you've visited, it almost becoming dull. "
    }
};

RoomGenerator::RoomGenerator(MobGenerator &mobGenerator) :
    mMobGenerator(mobGenerator) {

}

dc::model::Room *RoomGenerator::generate(unsigned int seed, unsigned int level) {
    srand(seed);

    int roomLevel = Random::nextInt(level - VARIANCE, level + VARIANCE);

    // create room
    dc::model::Room *room = new dc::model::Room(Point(0, 0), StringGenerator::generateString(roomDescriptions, seed));

    // populate room
    generateTraps(room, seed, level);
    generateMobs(room, seed, level);

    return room;
}

void RoomGenerator::generateTraps(dc::model::Room *room, unsigned int seed, unsigned int level) {
    if(rand() % 100 < 25) {
        int trapNum = rand() % 5;
        switch(trapNum) {
            case 0:
                room->addTrap(new dc::model::BearTrap());
                break;
            case 1:
                room->addTrap(new dc::model::EvilSummonTrap());
                break;
            case 2:
                room->addTrap(new dc::model::NearDeathTrap());
                break;
            case 3:
                room->addTrap(new dc::model::RatTrap());
                break;
            case 4:
                room->addTrap(new dc::model::TeleportTrap());
                break;
            default:break;
        }
    }
}

void RoomGenerator::generateMobs(dc::model::Room *room, unsigned int seed, unsigned int level) {
    dc::model::Mob *mob = mMobGenerator.generate(seed, level);

    // TODO: Fancy algoritme toepassen, om te bepalen of hier een mob moet komen

    room->addMob(mob);
}
