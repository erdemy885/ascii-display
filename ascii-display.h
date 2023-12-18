#ifndef ASCII_DISPLAY_H
#define ASCII_DISPLAY_H

class Window
{
public:
    Window(int x, int y);
    void draw(int x, int y, int b);
    void ref();
    void cls();
    int width, height;
};

#endif