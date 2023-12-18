#ifndef ASCII_DISPLAY_H
#define ASCII_DISPLAY_H

#include <string>
#if defined(_WIN32)
#include <windows.h>
#endif

class Window
{
public:
    Window(int x, int y);
    void draw(int x, int y, int b);
    void ref();
    void cls();
    int width, height;
private:
    const std::string brightness = " .,-~:;=!*#$@";
#if defined(_WIN32)
    char *screen;
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    DWORD dwBytesWritten = 0;
#endif
};

#endif