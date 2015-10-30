#ifndef DUNGEONCRAWLER_CONSOLE_H
#define DUNGEONCRAWLER_CONSOLE_H

#include <iostream>
#include <iomanip>

#if defined(__WIN32__) || defined(WIN32)
    #include <windows.h>
    #include <winbase.h>
    #include <wincon.h>
    #define _NO_OLDNAMES
    #include <conio.h>
#endif

namespace csl {
    /**
     * Enums: Color codes
     *
     * BLACK - Black
     * BLUE - Blue
     * GREEN - Green
     * CYAN - Cyan
     * RED - Red
     * MAGENTA - Magenta / purple
     * BROWN - Brown / dark yellow
     * GREY - Grey / dark white
     * DARKGREY - Dark grey / light black
     * LIGHTBLUE - Light blue
     * LIGHTGREEN - Light green
     * LIGHTCYAN - Light cyan
     * LIGHTRED - Light red
     * LIGHTMAGENTA - Light magenta / light purple
     * YELLOW - Yellow (bright)
     * WHITE - White (bright)
     */
    enum Color {
        BLACK = 0,
        BLUE  = 1,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        BROWN,
        GREY,
        DARKGREY,
        LIGHTBLUE,
        LIGHTGREEN,
        LIGHTCYAN,
        LIGHTRED,
        LIGHTMAGENTA,
        YELLOW,
        WHITE,
        COLOR_COUNT
    };

    const char * getANSIColor(const int c);

    typedef std::ios_base&(*ColorManipulatorType)(std::ostream &os, int c);
    struct ColorManipulator {
        ColorManipulatorType f;
        int i;
        ColorManipulator(ColorManipulatorType ff, int ii) : f(ff), i(ii) { };
    };

    template<typename C, typename Tr>
    std::basic_ostream<C, Tr>& operator <<(std::basic_ostream<C, Tr>& os, const ColorManipulator &m) {
        m.f(os, m.i);

        return os;
    };

    std::ios_base &setColorWindows(std::ostream &os, int c);
    std::ios_base &setColorUnix(std::ostream &os, int c);

    ColorManipulator color(int c);

    inline std::ostream &log() {
        return std::clog << color(GREY);
    }
}

#endif //DUNGEONCRAWLER_CONSOLE_H
