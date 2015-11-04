#include "util/ServiceLocator.h"
#include "spell/Spell.h"
#include "CastCommand.h"
#include "Game.h"
#include "Player.h"

namespace dc {
    namespace game {
        CastCommand::CastCommand(std::string spellName, dc::model::Game &game, dc::model::Player &player) :
            mSpellName(spellName),
            mGame(game),
            mPlayer(player) {

        }

        void CastCommand::execute() const {
            try {
                dc::model::Spell &spell = ServiceLocator::getInstance().resolve<dc::model::Spell>(mSpellName);
                if(mPlayer.mana() < spell.cost()) {
                    std::cout << "My mana is too low, I can't cast that spell." << std::endl;
                    return;
                }
                mPlayer.decreaseMana(spell.cost());
                spell.cast(mPlayer, mGame);
            } catch(NoSuchServiceException const &e) {
                std::cout << "What's that? That's not a spell is it?" << std::endl;
            }
        }

        bool CastCommand::isAction() const {
            return true;
        }

        CastCommand *CastCommand::create(Parameters &parameters) {
            dc::model::Game &game = ServiceLocator::getInstance().resolve<dc::model::Game>();
            dc::model::Player &player = game.player();

            return new CastCommand(parameters.param(0), game, player);
        }
    }
}
