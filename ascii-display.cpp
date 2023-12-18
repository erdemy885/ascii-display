#include "ascii-display.h"
#include <ncurses.h>
#include <string>
using namespace std;

const string brightness = " .,-~:;=!*#$@";

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