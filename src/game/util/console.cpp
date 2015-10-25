#include "util/console.h"

namespace csl {
    /**
     * Consts: ANSI color strings
     *
     * ANSI_CLS - Clears screen
     * ANSI_BLACK - Black
     * ANSI_RED - Red
     * ANSI_GREEN - Green
     * ANSI_BROWN - Brown / dark yellow
     * ANSI_BLUE - Blue
     * ANSI_MAGENTA - Magenta / purple
     * ANSI_CYAN - Cyan
     * ANSI_GREY - Grey / dark white
     * ANSI_DARKGREY - Dark grey / light black
     * ANSI_LIGHTRED - Light red
     * ANSI_LIGHTGREEN - Light green
     * ANSI_YELLOW - Yellow (bright)
     * ANSI_LIGHTBLUE - Light blue
     * ANSI_LIGHTMAGENTA - Light magenta / light purple
     * ANSI_LIGHTCYAN - Light cyan
     * ANSI_WHITE - White (bright)
     */
    const char* ANSI_CLS = "\033[2J";
    const char* ANSI_BLACK = "\033[22;30m";
    const char* ANSI_RED = "\033[22;31m";
    const char* ANSI_GREEN = "\033[22;32m";
    const char* ANSI_BROWN = "\033[22;33m";
    const char* ANSI_BLUE = "\033[22;34m";
    const char* ANSI_MAGENTA = "\033[22;35m";
    const char* ANSI_CYAN = "\033[22;36m";
    const char* ANSI_GREY = "\033[22;37m";
    const char* ANSI_DARKGREY = "\033[01;30m";
    const char* ANSI_LIGHTRED = "\033[01;31m";
    const char* ANSI_LIGHTGREEN = "\033[01;32m";
    const char* ANSI_YELLOW = "\033[01;33m";
    const char* ANSI_LIGHTBLUE = "\033[01;34m";
    const char* ANSI_LIGHTMAGENTA = "\033[01;35m";
    const char* ANSI_LIGHTCYAN = "\033[01;36m";
    const char* ANSI_WHITE = "\033[01;37m";

    const char *getANSIColor(const int c) {
        switch(c) {
            case BLACK : return ANSI_BLACK;
            case BLUE : return ANSI_BLUE; // non-ANSI
            case GREEN : return ANSI_GREEN;
            case CYAN : return ANSI_CYAN; // non-ANSI
            case RED : return ANSI_RED; // non-ANSI
            case MAGENTA : return ANSI_MAGENTA;
            case BROWN : return ANSI_BROWN;
            case GREY : return ANSI_GREY;
            case DARKGREY : return ANSI_DARKGREY;
            case LIGHTBLUE : return ANSI_LIGHTBLUE; // non-ANSI
            case LIGHTGREEN: return ANSI_LIGHTGREEN;
            case LIGHTCYAN: return ANSI_LIGHTCYAN; // non-ANSI;
            case LIGHTRED: return ANSI_LIGHTRED; // non-ANSI;
            case LIGHTMAGENTA: return ANSI_LIGHTMAGENTA;
            case YELLOW: return ANSI_YELLOW; // non-ANSI
            case WHITE: return ANSI_WHITE;
            default: return "";
        }
    }

    std::ios_base &setColorWindows(std::ostream &os, int c) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (WORD) c);

        return os;
    }

    std::ios_base &setColorUnix(std::ostream &os, int c) {
        os << getANSIColor(c);

        return os;
    }

    ColorManipulator color(int c) {
#if defined(__WIN32__)
        return ColorManipulator(&setColorWindows, c);
#else
        return ColorManipulator(&setColorUnix, c);
#endif
    }
}