#include "ascii-display.h"

#if defined(_WIN32)

#include <windows.h>

Window::Window(int x, int y){
    width = x;
    height = y;
    screen = new char[width*height];
    cls();
	SetConsoleActiveScreenBuffer(hConsole);
}

void Window::draw(int x, int y, int b){
    screen[y*width + x] = brightness[b];
}

void Window::ref(){
    WriteConsoleOutputCharacterA(hConsole, screen, width * height, { 0,0 }, &dwBytesWritten);
}

void Window::cls(){
    for (int i = 0; i < width*height; i++) {
        screen[i] = ' ';
    }
}

#elif defined(__APPLE__) || defined(__linux__)

#include <ncurses.h>

Window::Window(int x, int y)
{
    initscr();
    cbreak();
    curs_set(0);
    refresh();
    width = x;
    height = y;
}

void Window::draw(int x, int y, int b)
{
    if (0 <= x && 0 <= y && 0 <= b && x < width && y < height && b < 13)
    {
        mvaddch(y, x, brightness[b]);
    }
}

void Window::ref()
{
    refresh();
}

void Window::cls()
{
    erase();
}

#endif