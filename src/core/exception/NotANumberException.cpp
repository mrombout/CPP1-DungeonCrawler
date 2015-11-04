#include "NotANumberException.h"

NotANumberException::NotANumberException(const std::string &num) {

}

const char *NotANumberException::what() const throw() {
    return "Value is not a number.";
}
