#include "Number.h"

long Number::toLong(std::string &str) {
    char *endptr;
    errno = 0;
    long result = strtol(str.c_str(), &endptr, 10);

    if(endptr == str) {
        // could not convert
        // TODO: Throw exception?
        return -1;
    }
    if((result == LONG_MAX || result == LONG_MIN) && errno == ERANGE) {
        // out of range, handle or exit
        // TODO: Throw exception?
        return -1;
    }

    return result;
}
