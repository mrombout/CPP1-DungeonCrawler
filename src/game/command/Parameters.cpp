#include <sstream>
#include <vector>
#include "Parameters.h"

namespace dc {
    namespace game {
        Parameters::Parameters(std::string input) :
                mInput(input) {
            // split input on spaces
            std::stringstream inputstream(input);
            std::string s;

            while (getline(inputstream, s, ' ')) {
                mParameters.push_back(s.c_str());
            }

            // determine command name
            mCommandName = (mParameters.size() > 0) ? mParameters[0] : input;

            // remove command name from parameters
            if (mParameters.size() > 0) {
                mParameters.erase(mParameters.begin());
            }
        }

        const std::string &Parameters::commandName() const {
            return mCommandName;
        }

        const std::vector<std::string> Parameters::parameters() const {
            return mParameters;
        }

        unsigned int Parameters::num() const {
            return mParameters.size();
        }

        const std::string &Parameters::param(unsigned int paramNum) const {
            return mParameters[paramNum];
        }
    }
}
