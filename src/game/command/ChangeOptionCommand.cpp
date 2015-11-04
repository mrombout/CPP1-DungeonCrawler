#include <iostream>
#include "ChangeOptionCommand.h"
#include "Options.h"
#include "util/ServiceLocator.h"

namespace dc {
    namespace game {
        ChangeOptionCommand::ChangeOptionCommand(std::string name, std::string value) :
            mName(name),
            mValue(value) {

        }

        void ChangeOptionCommand::execute() const {
            dc::model::Options &options = ServiceLocator::getInstance().resolve<dc::model::Options>();
            std::string oldValue = options.get(mName);
            options.set(mName, mValue);

            std::cout << "Changed '" << mName << "' from " << oldValue << " to " << mValue << std::endl;
        }

        bool ChangeOptionCommand::isAction() const {
            return false;
        }
    }
}