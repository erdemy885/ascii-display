# ascii-display

## Description

**ascii-display** is a cross-platform library that allows you to use the terminal as a monochrome display. It features 13 different characters to represent various brightness levels: `" .,-~:;=!*#$@"`. This library was created as a cross-platform solution for writing to the terminal in various projects. At its core, ascii-display is a ncurses wrapper for Unix systems and a Windows API wrapper for Windows systems.

## Dependencies

- **Windows**: None required.
- **MacOS**: ncurses is needed. Install it via Homebrew: `brew install ncurses`
- **Linux**: ncurses is also required. Installation instructions for different distributions can be found [here](https://www.cyberciti.biz/faq/linux-install-ncurses-library-headers-on-debian-ubuntu-centos-fedora/).

## Instructions

- When compiling on **MacOS** or **Linux**, ensure to include the `-lncurses` tag at the end of your compile command.
- On **Windows**, adjust the terminal properties to match the size of your Window in the code. [Here's](https://pureinfotech.com/change-default-height-width-windows-terminal/) how you can do this on Windows 10 and 11

## Documentation

- **Window Class**: The main class where all methods of this library are stored. Initialize with `Window(int, int)`; the first int is the width, and the second int is the height of the window.
- **draw**: Writes a character at a coordinate based on the brightness value. Usage: `draw(int, int, int)`; the first int is the x-coordinate, the second int is the y-coordinate, and the third int is the brightness value (0 to 12).
- **drawc**: Similar to `draw`, but draws any ASCII character. Usage: `drawc(int, int, char)`; the first int is x, the second int is y, and the char is the ASCII character to be written.
- **ref**: Draws the contents of the screen buffer to the terminal. No parameters.
- **cls**: Clears the screen buffer. No parameters.
