#include "FileSystem.h"

#ifdef __WIN32__
#include <windows.h>
#endif

void FileSystem::mkdir(std::string &dir) {
    // TODO: There is experimental C++x API for this
#ifdef __WIN32__
    CreateDirectory(dir.c_str(), nullptr);
#else
    system("mkdir -p " + dir);
#endif
}
