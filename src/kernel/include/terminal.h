//
// Created by dev on 19/03/18.
//

#ifndef OS_TERMINAL_H
#define OS_TERMINAL_H

#include "types.h"
const uint16_t VGA_WIDTH = 80;
const uint16_t VGA_HEIGHT = 25;


enum vga_color{
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

#define WHITE_BLACK 0x07;

class Terminal {
private:
    unsigned char* video_memory = (unsigned char*)0xb8000;
    uint8_t cursor_x, cursor_y;
    uint8_t color;

    uint8_t vga_entry(enum vga_color fg, enum vga_color bg);
    void putchar(char c);
    void putint(int i);
    void init();




public:
    Terminal() { init(); }
    void set_pos(int x, int y);

    void set_color();
    void print(const char* str);
    void println(const char* str);
    void linebreak();
    void cls();
};


#endif //OS_TERMINAL_H
