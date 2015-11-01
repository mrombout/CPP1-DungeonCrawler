#include "FileSystem.h"

#ifdef __WIN32__
#include <windows.h>
#endif

void FileSystem::mkdir(std::string &dir) {
#ifdef __WIN32__
    CreateDirectory(dir.c_str(), nullptr);
#else
    system("mkdir -p " + dir);
#endif
}
