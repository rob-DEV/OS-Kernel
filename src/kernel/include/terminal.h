//
// Created by dev on 19/03/18.
//

#ifndef OS_TERMINAL_H
#define OS_TERMINAL_H

#include "types.h"

class Terminal {
private:
    unsigned char* video_memory = (unsigned char*)0xb8000;
    unsigned int cursor_x, cursor_y;
    //uint8_t color, background, foreground = 0;
    //uint8_t x, y = 0;
    //uint8_t make_color(uint8_t background, uint8_t foreground);

    void putch(char c);
    void putint(int i);

    void init();

public:
    void setpos(int x, int y);

    void print(const char* str);
    void println(const char* str);
    void linebreak();
    void cls();
};


#endif //OS_TERMINAL_H
