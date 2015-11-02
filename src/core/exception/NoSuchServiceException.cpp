#include <sstream>
#include "NoSuchServiceException.h"

NoSuchServiceException::NoSuchServiceException(const std::string &serviceName) {
    std::stringstream ss;
    ss << "Service '" << mServiceName << "' could not be found.";
    mWhat = ss.str().c_str();
}

const char *NoSuchServiceException::what() const throw() {
    return mWhat;
}
