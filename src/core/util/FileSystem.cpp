#include <stdlib.h>
#include "FileSystem.h"

#if defined (__WIN32__) || defined(WIN32)
	#include <windows.h>
#endif

void FileSystem::mkdir(std::string &dir) {
#if defined (__WIN32__) || defined(WIN32)
    CreateDirectory(dir.c_str(), nullptr);
#else
    std::string cmd = "mkdir -p " + dir;
    system(cmd.c_str());
#endif
}
