//
// Created by dev on 19/03/18.
//

#include "include/terminal.h"
#include "include/memory.h"
#include "include/string.h"

const uint16_t WIDTH = 80;
const uint16_t HEIGHT = 25;
#define WHITE_BLACK 0x07;

void Terminal::putch(char c) {
    if (c == '\n' || c == '\r')
    {
        cursor_x = 0;
        cursor_y++;
    }
    else
    {
        unsigned int position = cursor_y * WIDTH + cursor_x;
        unsigned char* memory = video_memory + position*2;
        *memory = c;
        *(memory+1) = WHITE_BLACK;
        cursor_x++;
        if (cursor_x == WIDTH)
        {
            cursor_x = 0;
            cursor_y++;
        }
    }

    if (cursor_y == HEIGHT) {
        memmove(video_memory, video_memory + (WIDTH * 2), (WIDTH * (HEIGHT - 1)) * 2);
        memset(video_memory + ((WIDTH * (HEIGHT - 1)) * 2), 0, WIDTH * 2);
        cursor_y--;
    }
}
void Terminal::setpos(int x, int y) {
    cursor_x = x;
    cursor_y = y;
}

void Terminal::print(const char *str) {
    int len = strlen(str);
    int i;
    for(i = 0; i < len; i++)
    {
        putch(str[i]);
    }
}

void Terminal::println(const char *str) {
    print(str);
    putch('\n');
}

void Terminal::linebreak()
{
    for(uint8_t i = 0; i < 80; i++) {
        print("-");
    }
}

void Terminal::cls(void) {
    unsigned char* memory = video_memory;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        *memory = ' ';
        *(memory+1) = WHITE_BLACK;
        memory += 2;
    }
    cursor_x = 0;
    cursor_y = 0;
}
