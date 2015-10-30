#include <stdlib.h>
#include <cerrno>
#include <limits.h>
#include "Number.h"
#include <exception>
#include "exception/NotANumberException.h"

long Number::toLong(const std::string &str) {
    char *endptr;
    errno = 0;
    long result = strtol(str.c_str(), &endptr, 10);

    if(endptr == str) {
        // could not convert
        throw new NotANumberException(str);
    }
    if((result == LONG_MAX || result == LONG_MIN) && errno == ERANGE) {
        // out of range, handle or exit
        throw new NotANumberException(str);
    }

    return result;
}

int Number::toInt(const std::string &str) {
    return static_cast<int>(toLong(str));
}
