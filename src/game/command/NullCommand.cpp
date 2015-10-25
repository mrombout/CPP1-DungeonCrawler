#include "NullCommand.h"

void dc::game::NullCommand::execute() const {

}

dc::game::NullCommand *dc::game::NullCommand::create(Parameters parameters) {
    return new dc::game::NullCommand();
}
